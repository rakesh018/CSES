#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// WE NEED TO IMPLEMENT countWordsEqualTo(), and countWordsStartsWith(), insert(), erase()
struct Node
{
    Node *links[26];
    int countPrefix = 0; // to track prefixes
    int endsWith = 0;    // to track end of the word

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a']; // gives link to reference node
    }

    void put(char ch, Node *node)
    {
        // if character does not exists put it
        links[ch - 'a'] = node;
    }
    void incrementPrefix()
    {
        countPrefix++;
    }

    void incrementEnd()
    {
        endsWith++;
    }

    void deleteEnd()
    {
        endsWith--;
    }

    void reducePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return endsWith;
    }

    int getPrefixes()
    {
        return countPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); // get next reference node
            // also increment prefix part
            node->incrementPrefix();
        }
        // increment endsWith part for last one
        node->incrementEnd();
    }

    int countWordsEqualTo(string word)
    {
        // count how many words exist in whole
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                // then move to reference node
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        // count how many words have word as a prefix
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefixes();
    }

    void erase(string word)
    {
        Node *node = root;
        // assuming word is guaranteed to exist
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return; // word dont exist
        }
        node->deleteEnd();
    }
};
int main()
{
    Trie test;
    vector<string> arr = {"apple", "ball", "app", "hello", "hell","apple"};
    for (string &c : arr)
    {
        test.insert(c);
    }

    cout<<test.countWordsEqualTo("apple")<<endl;
    cout<<test.countWordsEqualTo("hehe")<<endl;

    cout<<test.countWordsStartingWith("hel")<<endl;

    test.erase("ball");

    cout<<test.countWordsStartingWith("b");

    return 0;

}