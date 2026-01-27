#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
using namespace std;
struct Node{
     
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char ch , int freq){
        this->ch = ch;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

struct Compare{
    bool operator()(Node *a , Node *b){
        return a->freq > b->freq;
    }
};

void buildCodes(Node *root , string str , unordered_map<char , string> &mp){
    if(!root) return;

    if(!root->left && !root->right){
        mp[root->ch] = str;
    }

    buildCodes(root->left , str + '0' , mp);
    buildCodes(root->right , str + '1' , mp);
}

string decodeString(Node *root, const string &encoded){
    string decoded = "";
    Node *curr = root;

    for(char bit : encoded){
        if(bit == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if(!curr->left && !curr->right){
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main(){
    vector<pair<char , int>> arr ={
        {'A' , 6},
        {'B' , 7},
        {'C' , 4},
        {'D' , 5}
    };

    priority_queue<Node * , vector<Node *> , Compare> minHeap;

    for(auto &p : arr){
        minHeap.push(new Node(p.first , p.second));
    }

    while(minHeap.size() > 1){
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        Node *merge = new Node('#', left->freq + right->freq);
        merge->left = left;
        merge->right = right;

        minHeap.push(merge);
    }

    Node *root = minHeap.top();

    unordered_map<char , string> codes;
    buildCodes(root, "", codes);

    cout << "Enter the string to encode: ";
    string input;
    cin >> input;

    string encoded = "";
    for(char c : input){
        encoded += codes[c];
    }

    string decoded = decodeString(root, encoded);

    cout << "\nOriginal String : " << input << endl;
    cout << "Encoded String  : " << encoded << endl;
    cout << "Decoded String  : " << decoded << endl;

    return 0;
}