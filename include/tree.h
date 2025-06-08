// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>

struct Node {
    char value;
    explicit Node(char val);
    std::vector<std::shared_ptr<Node>> children;
    explicit Node(char val);
};

class PMTree {
 private:
    void BuildSubtree(std::shared_ptr<Node> node,
        const std::vector<char>& remaining);
    std::shared_ptr<Node> root;
    int permutation_count_;

 public:
    explicit PMTree(const std::vector<char>& symbols);
    std::shared_ptr<Node> GetRoot() const;
    int GetPermutationCount() const;
    friend std::vector<std::vector<char>> getAllPerms(PMTree& tree);
    friend std::vector<char> getPerm1(PMTree& tree, int num);
    friend std::vector<char> getPerm2(PMTree& tree, int num);
    friend void CountPermutationsImpl(const std::shared_ptr<Node>& node,
        int& count);
    static void CollectPermutations(const std::shared_ptr<Node>& node,
        std::vector<char>& path,
        std::vector<std::vector<char>>& result);
};

std::vector<char> getPerm1(PMTree& tree, int num);
std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm2(PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
