#include<iostream>
using namespace std;
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST
{
  public:
    TreeNode * root;
  BST()
  {
    root = NULL;
  }
  bool isTreeEmpty()
  {
    if (root == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void insertNode(TreeNode * new_node)
  {
    if (root == NULL)
    {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    }
    else
    {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value)
        {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        }
        else if ((new_node -> value < temp -> value) && (temp -> left == NULL))
        {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }
        else if (new_node -> value < temp -> value)
        {
          temp = temp -> left;
        }
        else if ((new_node -> value > temp -> value) && (temp -> right == NULL))
        {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }
        else
        {
          temp = temp -> right;
        }
      }
    }
  }

//=======preorder=====  

  void printPreorder(TreeNode * r) //(current node, Left, Right) 
  {
    if (r == NULL)
      return;
    /* first print data of node */
    cout << r -> value << " ";
    /* then recur on left sutree */
    printPreorder(r -> left);
    /* now recur on right subtree */
    printPreorder(r -> right);
  }
//=======inorder=====
  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> value << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  
  //=======postorder=====
  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
    if (r == NULL)
      return;
    // first recur on left subtree 
    printPostorder(r -> left);
    // then recur on right subtree 
    printPostorder(r -> right);
    // now deal with the node 
    cout << r -> value << " ";
  }
//=======iterativesearch=====
  TreeNode * iterativeSearch(int v)
  {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }
int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }
  
TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
TreeNode * deleteNode(TreeNode * r, int v) {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }

};

  



int main() {
  BST obj;
  int option, val;
  cout<<"====================================bst program================================="<<endl;

  do {
    cout << "What operation do you want to perform? " << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;  
    cout << "3. Print Preorder values" << endl;
    cout << "4. Print Inorder values" << endl;
    cout << "5. Print Postorder values" << endl;
    cout << "6. Delete node" << endl;
    cout << "7. Height of Tree" << endl;
    cout << "0. Exit Program" << endl;
    cout <<" Select Option number : " << endl;
    cin >> option;
    TreeNode * new_node = new TreeNode();
    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "INSERT node" << endl;
      cout << "Enter value of tree node to INSERT in BST: ";
      cin >> val;
      new_node -> value = val;
      obj.insertNode(new_node);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH the value..." << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;      
    case 3:
            cout <<"PRE-ORDER: ";
      	    obj.printPreorder(obj.root);
            cout<<endl;
      break;
    case 4:
            cout <<"IN-ORDER: ";
            obj.printInorder(obj.root);
      	    cout<<endl;
      break;
    case 5:
     	    cout <<"POST-ORDER: ";
            obj.printPostorder(obj.root);
      		cout<<endl;
      break;
    case 6:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 7:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    default:
      cout <<"Enter Proper Option number " << endl;
    }
  } while (option != 0);

  return 0;
}