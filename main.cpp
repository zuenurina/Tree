#include <iostream>
using namespace std;

struct node{
  string studId;
  int scorun;
  node *left, *right;
};

struct node *newScore(string id, int score){
  node *a = new node();
  a->studId = id;
  a->scorun = score;
  a->left = a->right = NULL;
  return(a);
}

struct node *insertScore(struct node *node, string id, int score){
  if(node == NULL){
    return(newScore(id, score));
  }

  else{
    if(score <= node->scorun){
      node->left = insertScore(node->left, id, score);
    }

    else{
      node->right = insertScore(node->right, id, score);
    }
    return node;
  }
}

void lowestScore(struct node *node){
  struct node* current = node;
	while (current->left != NULL){
    current = current->left;
  }
  cout << "\nLowest scorun is " << current->scorun << " from " << current->studId;
}

void highestScore(struct node *node){
  struct node* current = node;
	while (current->right != NULL){
    current = current->right;
  }
  cout << "\nHighest scorun is " << current->scorun << " from " << current->studId << endl;
}

void displayScore(struct node* node){
  if (node != NULL) {
    displayScore(node->left);
    cout << node->studId << " " << node->scorun << "\n"; 
    displayScore(node->right);
  } 
}

void searchScore(struct node* node, string find, int count){
  count++;
  
  while (node != NULL) {
    searchScore(node->left, find, count);

    if (node->studId == find){
      cout << "\nStudent ID: " << node->studId;
      cout << "\nScorun: " << node->scorun;
      cout << "\nTree Level: Level " << count << endl;
      break;
    }

    else {
      searchScore(node->right, find, count);
      break;
    }
    break;
  }
}

int main() {
  int i, score, no = 0;
  string id, search;

  struct node* root = NULL;

  while (i < 5){
    cout << "Enter student ID: ";
    getline(cin, id);

    cout << "Enter scorun: ";
    cin >> score;
    cout << endl;
    getchar();
    root = insertScore(root, id, score);
    i++;
  }

  displayScore(root);
  lowestScore(root);
  highestScore(root);

  cout << "\nEnter student ID: ";
  getline(cin, search);
  cout << "\n::Student Record::";
  searchScore(root, search, no);
} 