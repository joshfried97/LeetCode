#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) { 
        int retval = -1;

        auto search = m_cache.find(key);
        if (search != m_cache.end())
        {
            retval = search->second;

            // Move this key to the back of the vector as it was just accessed
            auto itr = find(m_keys.begin(), m_keys.end(), key);
            m_keys.erase(itr);
            m_keys.push_back(key);
        }       

        return retval;
    }
    
    void put(int key, int value) {
        auto search = m_cache.find(key);
        if (search != m_cache.end())
        {
            // Update an existing value
            m_cache.at(key) = value;
            m_keys.push_back(key);
        }
        else
        {
            // Add a new value
            if (m_cache.size() == m_capacity)
            {
                remove_least_accessed_element();
            }

            m_cache.insert({key, value});
            m_keys.push_back(key);
        }
    }

    void remove_least_accessed_element()
    {
        // We are at capacity therefore we need to remove the least accessed value
        const int least_accessed_key = m_keys[0];

        // Remove the cache item
        m_cache.erase(least_accessed_key);

        // Remove the key
        m_keys.erase(m_keys.begin());
    }

    void show_cache_contents()
    {
        std::cout << "Current cache contents are: " << std::endl;
        for (auto element : m_cache)
        {
            std::cout << "Key: " << element.first << " Value: " << element.second << std::endl;
        }        
    }

private:
    /// @brief This is our LRU cache
    std::unordered_map<int, int> m_cache;

    /// @brief This structure will tell us which key was accessed least; the most recent key will be pushed to the back of the vector
    /// therefore m_keys[0] should theoretically be the key to remove if we're full
    std::vector<int> m_keys;

    /// @brief Size of the cache
    int m_capacity;
};

int main() {
    cout << "Running solution for Challenge 146" << endl;

    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.show_cache_contents();

    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.show_cache_contents();

    std::cout << "lRUCache.get(1) returns " << lRUCache.get(1) << " should return 1" << std::endl;    // return 1

    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.show_cache_contents();

    lRUCache.get(2);    // returns -1 (not found)
    std::cout << "lRUCache.get(2) returns " << lRUCache.get(2) << " should return -1" << std::endl;    // return -1

    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.show_cache_contents();

    lRUCache.get(1);    // return -1 (not found)
    std::cout << "lRUCache.get(1) returns " << lRUCache.get(1)  << " should return -1" << std::endl;    // return -1

    lRUCache.get(3);    // return 3
    std::cout << "lRUCache.get(3) returns " << lRUCache.get(3)  << " should return 3" << std::endl;    // return 3

    lRUCache.get(4);    // return 4
    std::cout << "lRUCache.get(4) returns " << lRUCache.get(4)  << " should return 4" << std::endl;    // return 4

    return 0;
}