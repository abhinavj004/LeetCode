// INSERTION TIME COMPLEXITY O(m), m is the length of the string
// INSERTION SPACE COMPLEXITY O(m), 

// SEARCHING TIME COMPLEXITY O(m)
// SEARCHING SPACE COMPLEXITY O(1)



class TrieNode
{
    public:
    bool isword;
    TrieNode* children[26];
    TrieNode()
    {
        isword=false;
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root=new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int l=word.length();
        int k=0;
        TrieNode* curr=root;
        for(int i=0;i<l;i++)
        {
            k=word[i]-'a';
            if(curr->children[k]==nullptr)
                curr->children[k]=new TrieNode();
            curr=curr->children[k];
        }
        curr->isword=true;        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int l=word.length();
        int k=0;
        TrieNode* curr=root;
        for(int i=0;i<l;i++)
        {
            k=word[i]-'a';
            curr=curr->children[k];
            if(curr==nullptr)
                return false;
        }
        return curr->isword;       
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int l=prefix.length();
        int k=0;
        TrieNode* curr=root;
        for(int i=0;i<l;i++)
        {
            k=prefix[i]-'a';
            curr=curr->children[k];
            if(curr==nullptr)
                return false;
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */