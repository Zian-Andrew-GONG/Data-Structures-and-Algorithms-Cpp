#include <algorithm>
#include <iostream>
template <typename Comparable>
class BinarySearchTree {
 public:
  BinarySearchTree() : root{nullptr} {}
  ~BinarySearchTree() { makeEmpty(); }
  BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr} {
    root = clone(rhs.root);
  }
  BinarySearchTree& operator=(const BinarySearchTree& rhs) {
    root = clone(rhs.root);
    return *this;
  }
  BinarySearchTree(BinarySearchTree&& rhs) : root{nullptr} {
    root = clone(std::move(rhs.root));
  }
  BinarySearchTree& operator=(BinarySearchTree&& rhs) {
    root = clone(std::move(rhs.root));
    return *this;
  }

  const Comparable& findMin() const { findMin(root); }
  const Comparable& findMax() const { findMax(root); }
  bool contains(const Comparable& x) const { return contains(x, root); }
  bool isEmpty() const { return root == nullptr; }
  void printTree(std::ostream& out = std::cout) const;

  void makeEmpty() { makeEmpty(root); }
  void insert(const Comparable& x) { return insert(x, root); }
  void insert(Comparable&& x) { return insert(std::move(x), root); }
  void remove(const Comparable& x) { return remove(x, root); }

 private:
  struct BinaryNode {
    Comparable element;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
        : element{theElement}, left{lt}, right{rt} {}
    BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
        : element{theElement}, left{lt}, right{rt} {}
  };
  BinaryNode* root;
  void insert(const Comparable& x, BinaryNode*& t) {
    if (t == nullptr)
      t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
      insert(x, t->left);
    else if (x > t->element)
      insert(x, t->right);
    else
      ;
  }
  void insert(Comparable&& x, BinaryNode*& t) {
    if (t == nullptr)
      t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
      insert(std::move(x), t->left);
    else if (x > t->element)
      insert(std::move(x), t->right);
    else
      ;
  }
  void remove(const Comparable& x, BinaryNode*& t) {
    if (t == nullptr) return;
    if (x < t->element)
      remove(x, t->left);
    else if (x > t->element)
      remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) {
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
    } else {
      BinaryNode* oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right;
      delete oldNode;
    }
  }
  BinaryNode* findMin(BinaryNode* t) const {
    if (t == nullptr) return nullptr;
    if (t->left == nullptr) return t;
    return findMin(t->left);
  }
  BinaryNode* findMax(BinaryNode* t) const {
    if (t != nullptr)
      while (t->right != nullptr) {
        t = t->right;
      }
    return t;
  }
  bool contains(const Comparable& x, BinaryNode* t) const {
    if (t == nullptr)
      return false;
    else if (x < t->element)
      return contains(x, t->left);
    else if (x > t->element)
      return contains(x, t->right);
    else
      return true;
  }
  void makeEmpty(BinaryNode*& t) {
    if (t != nullptr) {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    t = nullptr;
  }
  void printTree(BinaryNode* t, std::ostream& out) const;
  BinaryNode* clone(BinaryNode* t) const {
    if (t == nullptr)
      return nullptr;
    else
      return new BinaryNode{t->element, clone(t->left), clone(t->right)};
  }
  BinaryNode* clone(BinaryNode*&& t) const {
    if (t == nullptr)
      return nullptr;
    else
      return new BinaryNode{std::move(t->element), clone(t->left),
                            clone(t->right)};
  }
};
