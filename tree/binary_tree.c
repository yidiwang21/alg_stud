#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Elemtype;

char *s = NULL;
int idx = 0;

typedef struct BTNode {
    Elemtype data;
    struct BTNode *left, *right;
}BTNode;

// FIXME: the first char not in the tree
BTNode *createNode() {
    BTNode *node;
    if (s[++idx] == '\0') node = NULL;
    else {
        node = (BTNode *)malloc(sizeof(BTNode));
        node->data = s[idx];
        printf("[%d] %c\n", idx, s[idx]);
        node->left = createNode();
        node->right = createNode();
    }
    return node;
}

void inOrderTrav(BTNode *node) {
    if (node) {
        inOrderTrav(node->left);
        printf("%c ", node->data);
        inOrderTrav(node->right);
    }
}

void preOrderTrav(BTNode *node) {
    if (node) {
        printf("%c ", node->data);
        preOrderTrav(node->left);
        preOrderTrav(node->right);
    }
}

void postOrderTrav(BTNode *node) {
    if (node) {
        postOrderTrav(node->left);
        postOrderTrav(node->right);
        printf("%c ", node->data);
    }
}

int getDepth(BTNode *node) {
    int l = 0, r = 0;
    if (!node) return 0;
    if (node->left) l = getDepth(node->left);
    if (node->right) r = getDepth(node->right);
    return (l > r)?(l + 1):(r + 1);
}

int getLeafNum(BTNode *node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    else return getLeafNum(node->left) + getLeafNum(node->right);
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./binary_tree [text]\n");
        return -1;
    }
    s = (char *)malloc(sizeof(char) * strlen(argv[1]));
    strcpy(s, argv[1]);

    BTNode *node = createNode();
    printf("Traversing: \n");
    preOrderTrav(node);
    printf("Depth: %d\n", getDepth(node));
    return 0;
}
