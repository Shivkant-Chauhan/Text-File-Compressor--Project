#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, //put greater in place of less for storing ordered set in desc order
        rb_tree_tag, tree_order_statistics_node_update> pbds;

        // find_by_order, order_of_key
//this is Policy-based Data Structure(PBDS)..


#define fastio()    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pb          push_back
#define ppb         pop_back
#define nln         '\n'
#define ff          first
#define ss          second
#define ins         insert
#define mod         1000000007
#define YES         cout << "YES";
#define NO          cout << "NO";
#define set_bits    __builtin_popcountll


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*  --------------------------------------------------------------------------------------------------------------  */


// template ..?
class TreeNode{
	public : 
	char data;
    int freq;
	TreeNode* left;
	TreeNode* right;

	TreeNode(char data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~TreeNode(){		
		delete left;
		delete right;
	}

};


// !!!!!
// this is the standard way of comparator function for a priority queue
// then we have to overload the operator function for our operation ...
class comparator{
    public: 
    bool operator()(TreeNode* l, TreeNode* r){
        return (l->freq > r->freq);
        // arranging as highest freq items first
    }
};


// Function to allocate a new tree node
TreeNode* getNode(char ch, int freq, TreeNode* left, TreeNode* right){
    TreeNode* node = new TreeNode(ch);

    node->data = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}


void encode(TreeNode* root, string str, unordered_map<char, string> &huffmanCode){
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


void decode(TreeNode* root, int &id, string str){
    if(root == nullptr){
        return;
    }

    if(!root->left && !root->right){
        cout << root->data;
        return;
    }

    id++;

    if (str[id] == '0')  decode(root->left, id, str);
    else                 decode(root->right, id, str);
}


/*  --------------------------------------------------------------------------------------------------------------  */

int main(){
    
    fastio();

    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        freopen("Error.txt", "w", stderr);
    #endif



    //reading files as in input.
        // i got full information as in string.
    //ignoring white spaces.
        //compress the file without loosing any information
        	//and without loosing white spaces indentation

    // string s = "panda shivkant aeiou bbbbbb";

    vector<string> input;

    string FileName;
    string inputStr = "";
    // cout << "enter the file name you want to compress" << nln;	//add feature when file location different
    // cin >> FileName;
    FileName = "TEXT_FILE.txt";

    ifstream readIN;
    readIN.open(FileName);
    while(!readIN.eof()){	//jab tk end of file nhi aa jata.
		string temp;
		getline(readIN, temp);

		input.pb(temp);

        inputStr += temp;
        inputStr += " ";

	}


//------------------------------------------------------------------------------------

    unordered_map<char, ll> freq;
    for(int i = 0; i < input.size(); i++){
    	string temp = input[i];
    	for(int k = 0; k < temp.size(); k++){
    		// if(temp[k] != ' '){
    			freq[temp[k]]++;
            // }
    	}

    }

//instead of this i should use priority queue
    // multimap<ll, char> rev_hsh;
    // for(auto &i : hsh){
    // 	// cout << i.first << " " << i.second << nln;
    // 	rev_hsh.insert({i.second, i.first});
    // }

    // for(auto &i : rev_hsh){
    // 	cout << i.first << " " << i.second << nln;
    // }

    // queue to store live nodes of Huffman tree;
    // priority_queue<TreeNode*, vector<TreeNode*>/*, comp*/> pq;
    priority_queue<TreeNode*, vector<TreeNode*>, comparator> pq;

//------------------------------------------------------------------------------------

//got stucked in the connections of the new nodes.

//------------------------------------------------------------------------------------
    //working on TreeNode

    // Create a leaf node for each character and add it to the priority queue.
    for (auto &x : freq) {
        pq.push(getNode(x.ff, x.ss, NULL, NULL));
    }
    

    while (pq.size() > 1){
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    TreeNode* root = pq.top();

    // ll k = 0;
    // char x;


  //   while(rev_hsh.size() != 1){

  //   	TreeNode<char> *parent, *leftCh, *rightCh;

  //   	auto iter = rev_hsh.begin();
  //   	auto min1 = iter;
  //   	auto min2 = ++iter;


  //   	x = '$' + k;
  //   	parent = new TreeNode<char>(x);
		// leftCh = new TreeNode<char>(min1->ff);
  //   	rightCh = new TreeNode<char>(min2->ff);

  //   	parent->left = leftCh;
  //   	parent->right = rightCh;


  //   	rev_hsh.ins({(min1->ff + min2->ff), x});
  //   	k++;
  //   	rev_hsh.erase(min1);
  //   	rev_hsh.erase(min2);


  //   	if(rev_hsh.size() == 1){
  //   		root = parent;
  //   	}


    // }


    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :" << nln << nln;
    for (auto &z : huffmanCode){
        cout << z.first << " " << z.second << nln;
    }


    // print encoded string
    string str = "";
    for (char ch: inputStr) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << str << nln;

    int index = -1;
    cout << "\nDecoded string is: " << nln;
    while (index < (int)str.size() - 2){
        decode(root, index, str);
    }



	// cout << rev_hsh.begin()->ff;
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
    // how to traverse on that tree..?

// cout << root->left->left->data;


    return 0;
}







