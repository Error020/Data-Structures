#include <iostream>
#include <string>
#include <random>

int randomNr() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 10);
    int nr = distr(gen);

    return nr;
}

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL) {}
};

struct AddResult {
    Node* node;
    bool inserted;
    std::string path;

    AddResult(Node* node, bool inserted, std::string path) : node(node), inserted(inserted), path(path) {}
};

AddResult add(Node* node, int value)
{
    bool inserted = false;
    std::string path = "root";

    while (node != NULL && value != node->data)
    {
        if (value > node->data)
        {
            if (node->right == NULL)
            {
                node->right = new Node(value);
                inserted = true;
            }
            path = path + "->right";
            node = node->right;
        }
        else
        {
            if (node->left == NULL)
            {
                node->left = new Node(value);
                inserted = true;
            }
            path = path + "->left";
            node = node->left;
        }
    }
    return AddResult(node, inserted, path);
}

struct FindResult
{
    Node* node;
    bool found;
    std::string path;

    FindResult(Node* node, bool found, std::string path) : node(node), found(found), path(path) {}
};

FindResult find(Node* node, int value)
{
    bool found = true;
    std::string path = "root";

    while (node != NULL && value != node->data)
    {
        if (value > node->data)
        {
            if (node->right == NULL)
                found = false;

            path = path + "->right";
            node = node->right;
        }
        else
        {
            if (node->left == NULL)
                found = false;

            path = path + "->left";
            node = node->left;
        }
    }
    return FindResult(node, found, path);
}

void worker(Node* root) {
    int nr = randomNr();
    FindResult result = find(root, nr);
    if (result.found == false)
        printf("%d was not found in the tree\n", nr);
    else
        printf("%d was Found in the tree at %s\n", nr, result.path.c_str());
}

int main()
{
    Node* root = new Node(5);
    printf("%d was made the root of the tree\n", 5);

    for (int i = 1; i <= 10; i += 2)
    {
        AddResult result = add(root, i);
        if (result.inserted == false)
            printf("%d was already in the tree at: %s\n", i, result.path.c_str());
        else
            printf("%d was added to the tree at: %s\n", i, result.path.c_str());
    }
    for (int i = 0; i <= 10; i += 2)
    {
        AddResult result = add(root, i);
        if (result.inserted == false)
            printf("%d was already in the tree at: %s\n", i, result.path.c_str());
        else
            printf("%d was added to the tree at: %s\n", i, result.path.c_str());
    }

    puts("");

    worker(root);

    return 0;
}
