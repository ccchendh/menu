#include <iostream>
#include <vector>

#include "linkList.h"

void callback_echo(linkNode::pointer head);
void callback_help(linkNode::pointer head);
void callback_exit(linkNode::pointer head);
void callback_version(linkNode::pointer head);

static std::vector<std::string> comdList = {"help", "echo", "version", "exit"};
static std::vector<linkNode::Function> callbackList = {callback_help, callback_echo, callback_version, callback_exit};

linkList makeComdList();

linkNode::pointer findComd(std::string comd, linkList head);

int main(){
    linkList head = makeComdList();
    std::string cmd;
    while(true){
        std::cout << "please input a cmd :";
        std::cin >> cmd;
        linkNode::pointer tmpCmd = findComd(cmd, head);
        if(!tmpCmd){
            std::cout << "invalid cmd!"<<std::endl;
            continue;
        }
        (tmpCmd->callback)(head);
    }
}

void callback_echo(linkNode::pointer head){
    bool flag = true;
    while(flag){
        std::string tmp;
        std::cin >> tmp;
        if(tmp == "q"){
            flag = false;
            continue;
        }
        std::cout << tmp << std::endl;    
    }

}

void callback_help(linkNode::pointer head){
    linkNode::pointer tmp = head->next;
    int count = 1;
    while(tmp){
        std::cout << count << ":" << tmp->name << std::endl;
        count++;
        tmp = tmp->next;
    }
}

void callback_version(linkNode::pointer head){
    std::cout << "version-2.0" << std::endl;
}

void callback_exit(linkNode::pointer head){
    exit(0);
}

linkList makeComdList(){
    linkList head = std::shared_ptr<linkNode>(new linkNode());
    linkNode::pointer tmp = head;
    for(int i = 0; i<comdList.size(); i++){
        linkNode::pointer newcomd = std::shared_ptr<linkNode>(new linkNode(comdList[i], callbackList[i]));
        tmp->next = newcomd;
        tmp = tmp->next;
    }
    return head;
}

linkNode::pointer findComd(std::string comd, linkList head){
    if(!head->next)
        return nullptr;
    linkNode::pointer tmp = head->next;
    while(tmp){
        if(tmp->name == comd)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}
