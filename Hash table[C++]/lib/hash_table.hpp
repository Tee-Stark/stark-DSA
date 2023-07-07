#include "hash_table.h"

template <class Key, class Value>
HashTable<Key, Value>::HashTable()
    : m_table(), m_max_load_factor(DEFAULT_LOAD_FACTOR), m_hashFunction(), m_size(0)
{
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable()
{
}

template <class Key, class Value>
typename HashTable<Key, Value>::Node *HashTable<Key, Value>::PrepareInsertion(const Key &key)
{
    if (m_size != 0)
    {
        std::size_t hashCode = m_hashFunction(key);
        std::size_t index = HashCodeToIndex(hashCode, BucketCount());
        Node *node = m_table[index];

        while (node != nullptr)
        {
            if (node->key == key)
                return node;
            node = node->next;
        }
    }

    if (m_size + 1 > BucketCount() * m_max_load_factor || BucketCount() == 0)
    {
        std::size_t size = (BucketCount() == 0) ? 1 : 2 * (m_size + 1) / m_max_load_factor;
        Rehash(size);
    }

    return nullptr;
}

template <class Key, class Value>
std::size_t HashTable<Key, Value>::BucketCount() const
{
    return m_table.size();
}

template <class Key, class Value>
std::size_t HashTable<Key, Value>::HashCodeToIndex(std::size_t hashCode, std::size_t bucketCount)
{
    return (hashCode < bucketCount) ? hashCode : hashCode % bucketCount;
}

template <class Key, class Value>
void HashTable<Key, Value>::Rehash(const std::size_t size)
{
    std::vector<Node *> newTable(size, nullptr);

    if (BucketCount() != 0)
    {
        for (int i = 0; i < BucketCount(); i++)
        {
            Node *currentNode = m_table[i];

            while (current_node != nullptr)
            {
                Node *temp = currentNode;
                currentNode = currentNode->next;
                temp->next = nullptr;

                std::size_t index = HashCodeToIndex(temp->hash_code, size);

                Node *currentSlotNode = newTable[index];
                if (currentSlotNode == nullptr)
                {
                    newTable[index] = temp;
                }
                else
                {
                    while (currentSlotNode->next != nullptr)
                        currentSlotNode = currentSlotNode->next;

                    currentSlotNode->next = temp;
                }
            }
        }
    }
    m_table = newTable;
}

// TODO: Insert method
// TODO: Remove method
// TODO: At method
