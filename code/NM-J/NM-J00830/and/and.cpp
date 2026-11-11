#include<bits/stdc++.h>
using namespace std;
unsigned int _and(std::vector<unsigned int> data){
    unsigned int ret=data[0];
    for(int i=1;i<data.size();i++)
        ret&=data[i];
    return ret;
}
bool _2(std::vector<unsigned int> data){
    unsigned int last=data[0];
    for(int i=1;i<data[i];i++){
        if(data[i]!=last*2)
            return false;
        last=data[i];
    }
    return true;
}
std::vector<std::vector<unsigned int>> _find(int start,int n,std::vector<unsigned int> data){
    std::vector<std::vector<unsigned int>> ret,ls1;
    std::vector<unsigned int> ls;
    if(n==1)return {{data[start]}};
    //4-2+1,3+1=4
    for(int i=start+1;i<=data.size()-n+1;i++){
        ls1=_find(i,n-1,data);
        for(int j=0;j<ls1.size();j++){
            ls.push_back(data[start]);
            for(int k=0;k<ls1[j].size();k++){
                ls.push_back(ls1[j][k]);
            }
            ret.push_back(ls);
            ls.clear();
        }
    }
    return ret;
}
int main(){
    unsigned int result;
    unsigned int max; 
    int n,m;
    fstream read;
    read.open("and.in",ios_base::in);
    read>>n>>m;
    std::vector<unsigned int> a;
    std::vector<std::vector<unsigned int>> list,_ls;
    a.resize(n);
    for(int i=0;i<n;i++)
        read>>a[i];
    if(n==m){
        max=_and(a);
        goto end;
    }
    for(int i=0;i<n-m;i++){
        _ls=_find(i,m,a);
        for(int i=0;i<_ls.size();i++)
            list.push_back(_ls[i]);
    }
    max=0;unsigned int ls;
    for(int i=0;i<list.size();i++){
        for(int j=0;j<list[i].size();j++)
            cout<<list[i][j]<<" ";
            cout<<endl;
        ls=_and(list[i]);
        if(ls>max)max=ls;
    }
    end:
    fstream write;
    write.open("and.out",ios_base::out);
    write<<max;
    return 0;
}