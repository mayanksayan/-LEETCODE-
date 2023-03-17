class node {
public:
	unordered_map<char, node*> m;
	bool isTerminal;
	node()
	{
		isTerminal = false;
	}
};

class Trie {
public:
    /** Initialize your data structure here. */

	node* root;

    Trie() {
        root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        node *temp = root;
        for(int i = 0 ; word[i] != '\0' ; i++)
        {
        	if(temp -> m.find(word[i]) == temp -> m.end())

        	temp = temp -> m[word[i]];
        }
		temp -> isTerminal = true;                                  

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        node *temp = root;
        for(int i = 0 ; word[i] != '\0' ; i++)
        {
        	if(temp -> m.find(word[i]) == temp -> m.end())
				return false;                                                 
        	temp = temp -> m[word[i]];
        }
        return (temp -> isTerminal);                                
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        node *temp = root;
        for(int i = 0 ; prefix[i] != '\0' ; i++)
        {
        	if(temp -> m.find(prefix[i]) == temp -> m.end())
        		return false;
        	temp = temp -> m[prefix[i]];
        }
        return true;                      
    }
};
