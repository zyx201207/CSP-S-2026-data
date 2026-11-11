#include<bits/stdc++.h>
using namespace std;
class Struct{
    public:
    Struct* big;
    Struct* small;
    int data;
    int size=1;
    Struct(int d){
        big=nullptr;
        small=nullptr;
        data=d;
    }
    Struct(Struct* children,int d){
        big=nullptr;
        small=children;
        data=d;
    }
    void insert(int a){
        if(a==data)size++;
        if(a>data){
            if(big==nullptr)big=new Struct(this,a);
            else big->insert(a);
        }
        if(a<data){
            if(small=nullptr)small=new Struct(this,a);
            else small->insert(a);
        }
    }
    void out(std::vector<int>* list){
        if(small!=nullptr)
            small->out(list);
        for(int i=0;i<size;i++)
            list->push_back(data);
    }
    void result(std::vector<int>* list){
        if(big!=nullptr){
            big->result(list);
            return;
        }
        out(list);
    }
};
int test(int k,std::vector<int> e_list,int oper_num,bool limit){
    int oper=oper_num;
    int result=0;
    std::vector<int> can_oper;
    for(int i=0;i<e_list.size();i++)
        if(e_list[i]<=e_list[k])
            can_oper.push_back(e_list[i]);
    Struct tool=Struct(can_oper[0]);
    for(int i=1;i<can_oper.size();i++)
        tool.insert(can_oper[i]);
    can_oper.clear();
    tool.result(&can_oper);
    for(int i=can_oper.size()-1;i>=0;i--){
        if(can_oper[i]==e_list[k]){
            result++;
            continue;
        }
        oper_num-=e_list[k]-can_oper[i];
        if(oper_num<0)return result;
        if(oper_num==0)return result+1;
        result++;
    }
    if(limit)return result;
    if(oper_num==0)return result;
    int data=test(k+1,e_list,oper,k+1==e_list.size());
    return data>result?data:result;
}
int main(){
    fstream read;
    read.open("crystal.in",ios_base::in);
    int n,m;
    read>>n>>m;
    std::vector<int> e_list(n);
    for(int i=0;i<n;i++)
        read>>e_list[i];
    int max=test(0,e_list,m,false);
    fstream write;
    write.open("crystal.out",ios_base::out);
    write<<max;
    return 0;
}