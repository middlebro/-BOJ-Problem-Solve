//
//  main.cpp
//  [1991]Tree traversal
//
//  Created by 서형중 on 10/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char value) {
        this->data = value;
        left = right = NULL;
    }
};
struct tree {
    Node* root;
    vector<Node*> node_list;
    
    tree() {
        for (int i = 0; i < 26; ++i) {
            Node* tmp = new Node(i + 'A');
            node_list.push_back(tmp);
        }
        root = node_list[0];
    }

    void inorder(Node* v) {
        if (v != NULL) {
            inorder(v->left);
            cout << v->data;
            inorder(v->right);
        }
        return;
    }
    void preorder(Node* v) {
        if (v != NULL) {
            cout << v->data;
            preorder(v->left);
            preorder(v->right);
        }
        return;
    }
    void postorder(Node* v) {
        if (v != NULL) {
            postorder(v->left);
            postorder(v->right);
            cout << v->data;
        }
        return;
    }
};
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    tree T;
    while (n--) {
        char par, left, right;
        cin >> par >> left >> right;
        if (left != '.')
            T.node_list[par - 'A']->left = T.node_list[left - 'A'];
        if (right != '.')
            T.node_list[par - 'A']->right = T.node_list[right - 'A'];
    }
    T.preorder(T.root); cout << endl;
    T.inorder(T.root); cout << endl;
    T.postorder(T.root); cout << endl;
    return 0;
}

