#ifndef LINKLIST_H
#define LINKLIST_H

#include<string>
#include <memory>



typedef struct linkNode
{
    typedef std::shared_ptr<linkNode> pointer;
    typedef void(*Function)(pointer);
    linkNode(std::string name = "head", Function callback = nullptr) : name(name), callback(callback), next(nullptr) {}
    std::string name;
    Function callback;
    pointer next;

}linkNode;

typedef std::shared_ptr<linkNode> linkList;



#endif // !LINKLIST_H

