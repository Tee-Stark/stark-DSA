#include <vector>

template <class Key, class Value>
class HashTable
{
    struct Node
    {
        Key key;
        Value value;
        std::size_t hash_code;
        Node *next;
    };

public:
    HashTable();
    ~HashTable();

private:
    Node *PrepareInsertion(const Key &key);
    inline std::size_t BucketCount() const;

    std::size_t m_size;
    double m_max_load_factor;
    std::hash<Key> m_hashFunction;
    std::vector<Node *> m_table;
    std::size_t HashCodeToIndex(std::size_t hashCode, std::size_t bucketCount);
    void Rehash(std::size_t size);
    static constexpr double DEFAULT_LOAD_FACTOR = 0.75d;
};
