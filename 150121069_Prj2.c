#include <stdio.h>
#include <stdlib.h>
int y=0;
int x=0;
int a;
int *b=&a;
 struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};


struct Node* newNode(int key) {

  struct Node* node =(struct Node*)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int depth(struct Node *node) {
  if (node == NULL) {
    return 0;
  }
  int left = depth(node->left);
  int right = depth(node->right);
  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}
struct Node *leftRotate(struct Node* node){
    struct Node *nodeRight=node->right;
    struct Node *nodeRightLeft=nodeRight->left;

    nodeRight->left=node;
    node->right=nodeRightLeft;

    return nodeRight;
}
struct Node *rightRotate(struct Node *node) {
  struct Node *nodeLeft=node->left;
  struct Node *nodeLeftRight=nodeLeft->right;

  nodeLeft->right=node;
  node->left=nodeLeftRight;

  return nodeLeft;
}
struct Node *zigzig(struct Node* node){
    struct Node *nodeLeft=node->left;
    struct Node *nodeLeftLeft=nodeLeft->left;
    struct Node *nodeLeftRight=nodeLeft->right;
    struct Node *nodeLeftLeftRight=nodeLeftLeft->right;
    nodeLeft->right=node;
    nodeLeftLeft->right=nodeLeft;
    nodeLeft->left=nodeLeftLeftRight;
    node->left=nodeLeftRight;

    return nodeLeftLeft;
}
struct Node *zagzag(struct Node* node){
    struct Node *nodeRight=node->right;
    struct Node *nodeRightRight=nodeRight->right;
    struct Node *nodeRightLeft=nodeRight->left;
    struct Node *nodeRightRightLeft=nodeRightRight->left;

    nodeRightRight->left=nodeRight;
    nodeRight->left=node;
    nodeRight->right=nodeRightRightLeft;
    node->right=nodeRightLeft;

    return nodeRightRight;

}


struct Node* fixBalance(struct Node *node){
    if((depth(node->left) - depth(node->right))==2){
        if((depth(node->left->left) - depth(node->left->right))==1){
            return rightRotate(node);
        }
        else{
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    else if((depth(node->left) - depth(node->right))==-2){
        if((depth(node->right->left) - depth(node->right->right))==-1){
            return leftRotate(node);
        }
        else{
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;

}

struct Node* insert(struct Node* node, int key) {
    if (node==NULL) {y++;
        return newNode(key);
    }
    if (node->key < key) {y++;
        node->right=insert(node->right, key);
    }
    else if (key < node->key) {y++;
        node->left=insert(node->left, key);
    }
    else {
        return node;
    }
    fixBalance(node);

}
struct Node* insertSplay(struct Node *node, int key){
     if (node==NULL) {x++;
        return newNode(key);
    }
    if (node->key < key) {x++;
        node->right=insertSplay(node->right, key);
    }
    else if (key < node->key) {x++;
        node->left=insertSplay(node->left, key);
    }
    else {
        return node;
    }
}

struct Node *splay(struct Node *root, int key) {
  if (root == NULL) {x++;
        return root;
  }

  if (key == root->key){
     return root;
    }
  if (key < root->key) {x++;
      /*if(key < root->left->key){
            root->left->left = splay(root->left->left, key);
            zigzig(root);
      }*/
    root->left = splay(root->left, key);
    root = rightRotate(root);
  }
  else {x++;
        /*if(key > root->right->key){
            root->right->right = splay(root->right->right, key);
            zagzag(root);
        }*/
    root->right = splay(root->right, key);
    root=leftRotate(root);
  }
  return root;
}


int element(struct Node* node, int key){

    if (node->key < key) {
        a++;
        node->right=element(node->right, key);
    }
    else if (key < node->key) {
        a++;
        node->left=element(node->left, key);
    }
    else {
        if(a%2==1){
            return 1;
        }
        return 2;
    }

}



void printTree(struct Node* node) {

  if (node == NULL) {
    return;
  }
  printf("%d ", node->key);
  printTree(node->left);
  printTree(node->right);


}

int main(int argc,char* argv[]){

    if(argc==1)
       printf("Error message!");
    if(argc>=2)
    {

        FILE* input_file = fopen(argv[1],"r");
        if(input_file == NULL){
            printf("File not found");
            return 0;
        }
        struct Node* rootAvl = NULL;
        struct Node* rootSplay = NULL;

       int number;
        while(fscanf(input_file,"%d",&number)==1){

            rootAvl=insert(rootAvl,number);
            rootSplay=insertSplay(rootSplay,number);
            rootSplay=splay(rootSplay,number);

        }
        printf("AVL tree:\n");
        printTree(rootAvl);
        printf("\nTotal cost: ");
        printf("%d\n",y);
        printf("\nSplay tree:\n");
        printTree(rootSplay);
        printf("\nTotal cost: ");
        printf("%d\n",x);

        fclose(input_file);
        return 0;
     }

    }
