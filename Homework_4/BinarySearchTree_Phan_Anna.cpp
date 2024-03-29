//Written by Anna Phan
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class TreeNode {
public:
  int data;
  TreeNode* leftChild;
  TreeNode* rightChild;

  TreeNode(int aData){
    data = aData;
    leftChild = rightChild = nullptr;
  }
}; 

class BinarySearchTree{
private:
  TreeNode* root; // head

public:
  BinarySearchTree() {
    root = nullptr;
  }

  //add a data
  void add(int aData) {
    root = add(root, aData);
  }

  TreeNode* add(TreeNode* aNode, int aData) {
    if (aNode == nullptr) {
      return new TreeNode(aData);
    }

    if (aData < aNode->data) {
      aNode->leftChild = add(aNode->leftChild, aData);
    } else if (aData > aNode->data) {
      aNode->rightChild = add(aNode->rightChild, aData);
    } else {
      cout << "Node " << aData << " is a duplicate node. Cannot insert it again." << endl;
    }

    return aNode;
  }

  //delete a node
  void remove(int aData){
    root = remove(root, aData);
  }

  TreeNode* remove(TreeNode* aNode, int aData){
    if(aNode == nullptr){
      return nullptr;
    } else if(aData < aNode->data){
      aNode->leftChild = remove(aNode->leftChild, aData);
    } else if(aData > aNode->data) {
      aNode->rightChild = remove(aNode->rightChild, aData);
    } else {
      if(aNode->leftChild == nullptr){
        cout << "Node " << aData << " has been deleted." << endl;
        return aNode->rightChild;
      } else if(aNode->leftChild == nullptr){
        cout << "Node " << aData << " has been deleted." << endl;
        return aNode->leftChild;
      } else {
        cout << "Node " << aData << " cannot be found." << endl;
      }

      TreeNode* temp = findMinInTree(aNode->rightChild);
      aNode->data = temp->data;
      aNode->rightChild = remove(aNode->rightChild, temp->data);
    }

    return aNode;
  }

  TreeNode* findMinInTree(TreeNode* aNode) {
    if(aNode == nullptr){
      return nullptr;
    } else if (aNode->leftChild == nullptr){
      return aNode;
    } else {
      return findMinInTree(aNode->leftChild);
    }
  }

  //search for a data
  void search(int aData){
    TreeNode* result = search(root, aData);
    if (result) {
      cout << "Node " << aData << " found. Path: ";
      printPath(root, aData);
    } else {
      cout << aData << " not found. Path: ";
      printPath(root, aData);
    }
  }

  TreeNode* search(TreeNode* aNode, int aData){
    if(aNode == nullptr || aNode->data == aData){
      return aNode;
    }

    if(aData < aNode->data){
      return search(aNode->leftChild, aData);
    } else if (aData > aNode->data) {
      return search(aNode->rightChild, aData);
    } else {
      cout << "Node does does not exist in tree.";
    }
    return aNode;
  }

  void printPath(TreeNode* aNode, int aData) {
    if (aNode == nullptr) {
      cout << "search key not found";
      return;
    } 

    cout << aNode->data << " → ";

    if (aNode->data == aData)
      return;

    if (aData < aNode->data)
      printPath(aNode->leftChild, aData);
    else
      printPath(aNode->rightChild, aData);
  }

  //finding tha smallest
  int findSmallest() {
    TreeNode* current = root;
    while (current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current->data;
  }

  //finding the largest
  int findLargest() {
    TreeNode* current = root;
    while (current->rightChild != nullptr) {
        current = current->rightChild;
    }
    return current->data;
  }

  void display() {
    cout << "BST nodes are: ";
    inOrderTraversal(root);
    cout << endl;
  }

  //prints in order
  void inOrderTraversal(TreeNode* aNode) {
    if (aNode == nullptr) {
      return;
    }
    inOrderTraversal(aNode->leftChild);
    cout << aNode->data << " ";
    inOrderTraversal(aNode->rightChild);
  }

};

int main(){
  BinarySearchTree bst;
  int choice;

  // cout << "testing 5 3 1 4 7 8" << endl;
  // bst.add(5);
  // bst.add(3);
  // bst.add(1);
  // bst.add(4);
  // bst.add(7);
  // bst.add(8);

  do {
    cout << "Select one of the following operations:" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. Search for a Node" << endl;
    cout << "4. Find Smallest Node" << endl;
    cout << "5. Find Largeest Node" << endl;
    cout << "0. Exit program" << endl;
    cout << "Enter your number choice" << endl;
    cin >> choice; 

    switch(choice){
      case 1: //add value
        int addValue;
        cout << "Enter the value to add: ";
        cin >> addValue;
        bst.add(addValue);
        bst.display();
        break;

      case 2: //delete value
        int removeValue;
        cout << "Enter the value to delete: ";
        cin >> removeValue;
        bst.remove(removeValue);
        bst.display();
        break;

      case 3: //search for value
        int searchValue;
        cout << "Enter the value to search: ";
        cin >> searchValue;
        bst.search(searchValue);
        cout << endl;
        bst.display();
        break;

      case 4:
        cout << "Smallest Node: " << bst.findSmallest() << endl;
        bst.display();
        break;

      case 5:
        cout << "Largest Node: " << bst.findLargest() << endl;
        bst.display();
        break;

      case 0:
        cout << "Exiting program" << endl;
        cout << "Goodbye" << endl;
        break;

      default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
  } while (choice != 0);

  return 0;
}