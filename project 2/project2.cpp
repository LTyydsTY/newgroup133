#include <iostream>
#include <unordered_set>

struct Node {
    int value;
    struct Node* nextNode;
};

struct Node* findCycleStart(struct Node* head) {
    std::unordered_set<struct Node*> visitedNodes;

    while (head != nullptr) {
        if (visitedNodes.count(head) > 0) {
            return head;
        }

        visitedNodes.insert(head);
        head = head->nextNode;
    }

    return nullptr;
}

struct Node* createNode(int value) {
    struct Node* newNode = new struct Node;
    newNode->value = value;
    newNode->nextNode = nullptr;
    return newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->nextNode = createNode(2);
    head->nextNode->nextNode = createNode(3);
    head->nextNode->nextNode->nextNode = createNode(4);
    head->nextNode->nextNode->nextNode->nextNode = head->nextNode;

    struct Node* startNodeOfCycle = findCycleStart(head);

    if (startNodeOfCycle != nullptr) {
        std::cout << "Cycle detected. Starting node value: " << startNodeOfCycle->value << std::endl;
    }
    else {
        std::cout << "No cycle found" << std::endl;
    }

    return 0;
}