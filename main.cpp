/*

make new .cpp files and then include them to this main file..
just like web dev bruh..!

*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pb push_back
#define ppb pop_back
#define nln '\n'
#define ff first
#define ss second
#define ins insert
#define mod 1000000007
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;



template <typename T>
class TreeNode{
	public : 
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;

	TreeNode(T data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~TreeNode(){		// executed when delete root encountered..
		delete left;	//first delete both its child, then automatically root as executed when delete root is encountered in code
		delete right;	//not automatically executed as all nodes are dynamically allocated.
	}

	void insert(T data){
		

		
	}

};



int main(){
    
    fastio();

    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif



    //reading files as in input.
        // i got full information as in string.
    //ignoring white spaces.
        //compress the file without loosing any information
        	//and without loosing white spaces indentation

    // string s = "panda shivkant aeiou bbbbbb";

    vector<string> input;

    string FileName;
    // cout << "enter the file name you want to compress" << nln;	//add feature when file location different
    // cin >> FileName;
    FileName = "TEXT_FILE.txt";

    ifstream readIN;
    readIN.open(FileName);
    while(!readIN.eof()){	//jab tk end of file nhi aa jata.
		string temp;
		getline(readIN, temp);

		input.pb(temp);

	}


//------------------------------------------------------------------------------------
    //instead of this how can i use min priority queue...?


    map<char, int> hsh;
    for(int i = 0; i < input.size(); i++){
    	string temp = input[i];
    	for(int k = 0; k < temp.size(); k++){
    		if(temp[k] != ' ')
    			hsh[temp[k]]++;
    	}
    }

    multimap<int, char> temp_hsh;
    for(auto &i : hsh){
    	cout << i.first << " " << i.second << nln;
    	temp_hsh.insert({i.second, i.first});
    }

    vector<char> min_wise_char;
    for(auto &i : temp_hsh){
    	min_wise_char.pb(i.second);
    }



    //instead of this how can i use min priority queue...?
//------------------------------------------------------------------------------------






    return 0;
}







