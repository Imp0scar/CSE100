// #include <iostream>

// using namespace std;


// int Huffman()




// int main(){

// int A, B, C, D, E, F;

// cin >> A >> B >> C >> D >> E >> F;




// cout << "A:" << A;
// cout << "B:" << B;
// cout << "C:" << C;
// cout << "D:" << D;
// cout << "E:" << E;
// cout << "F:" << F;




// return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char symbol;
    int frequency;
    Node *left, *right;

    Node(char symbol, int frequency) {
        this->symbol = symbol;
        this->frequency = frequency;
        this->left = this->right = nullptr;
    }

    Node(Node* left, Node* right) {
        this->symbol = '\0';
        this->frequency = left->frequency + right->frequency;
        this->left = left;
        this->right = right;
    }

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }
};

// Comparison operator for priority queue
class NodeComparator {
public:
    bool operator()(Node* lhs, Node* rhs) const {
        return lhs->frequency > rhs->frequency;
    }
};

// Builds Huffman Tree based on symbol frequency
Node* buildHuffmanTree(const vector<int>& frequencies) {
    priority_queue<Node*, vector<Node*>, NodeComparator> pq;

    for (char symbol = 'A'; symbol <= 'F'; symbol++) {
        int frequency = frequencies[symbol - 'A'];
        pq.push(new Node(symbol, frequency));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        pq.push(new Node(left, right));
    }

    return pq.top();
}

// Generates Huffman Codes from Huffman Tree
void generateHuffmanCodes(Node* root, string code, map<char, string>& codes) {
    if (root->isLeaf()) {
        codes[root->symbol] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

int main() {
    vector<int> frequencies(6);

    // Read input frequencies
    for (int i = 0; i < 6; i++) {
        cin >> frequencies[i];
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(frequencies);

    // Generate Huffman Codes
    map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    // Output Huffman Codes
    for (char symbol = 'A'; symbol <= 'F'; symbol++) {
        cout << symbol << ":" << codes[symbol] << endl;
    }

    return 0;
}
