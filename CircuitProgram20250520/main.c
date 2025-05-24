//
//  main.c
//  CircuitProgram20250520
//
//  Created by 박준하 on 5/20/25.
//

//트리를 사용한 순회 프로그램 만들어보기

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

// 중위 순회
void inorder (TreeNode *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("[%d] ", root->data);
    inorder(root->right);
  }
}

// 전위 순회
void preorder (TreeNode *root) {
  if (root != NULL) {
    printf("[%d] ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// 후위 순회
void postorder (TreeNode *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("[%d] ", root->data);
  }
}

int main(void) {
  printf("중위순회 = ");
  inorder(root);
  printf("\n");

  printf("전위순회 = ");
  preorder(root);
  printf("\n");

  printf("후위순회 = ");
  postorder(root);
  printf("\n");

  return 0;
}
