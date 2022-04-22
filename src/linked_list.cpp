#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* node = front_;
    Node* prev = nullptr;
    Node* next = nullptr;
    for (int i = 0; i < size_; i++) {
      next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    prev = back_;
    back_ = front_;
    front_ = prev;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_, nullptr);
      Node* prev = back_;
      back_ = front_;
      front_ = prev;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    Node* node = curr->next;
    curr->next = prev;
    if (node) {
      reverse_recursive_helper(node, curr);
    }
  }

}  // namespace assignment
