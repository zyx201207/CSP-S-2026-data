#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    vector<Tree*> last;
    vector<Tree*> next;
    int id;
    int d;
    Tree(int _id,int _d){
        id=_id;
        d=_d;
    }
    void insert(int data){
        if(data-id<=d){
            next.push_back(new Tree(data,d));
            return;
        }
        for(int i=0;i<next.size();i++)
            next[i]->insert(data);
    }
    int get(int data){
        if(data-id<=d)
            return data-id;
        
    }
};
struct KV{int a;int b;};
//can to road
vector<vector<int>> road(int u,int v,int d,std::vector<int> x){
    int min=-1;
    if(v-u==1)return {{u,v}};
    std::vector<vector<int>> ret,ls3;
    std::vector<int> ls,ls2;
    for(int i=u+1;i<v;i++)
        if(x[i]-x[u]<=d)ls.push_back(i);
    for(int i=0;i<ls.size();i++){
        ls3=road(ls[i],v,d,x);
        for(int j=0;j<ls3.size();j++){
            ls2.push_back(u);
            for(int k=0;k<ls3[j].size();k++){
                ls2.push_back(ls3[j][k]);
            }
            ret.push_back(ls2);
            ls2.clear();
        }
    }
}
std::vector<KV> rehas(vector<int> data){
    std::vector<KV> ret;
    for(int i=0;i<data.size();i++)
    for(int j=i+1;j<data.size();j++)
        if(data[i]==data[j])
            ret.push_back({i,j});
}
int get(int n,int d,std::vector<int> x){
    vector<vector<int>> _road;
    vector<int> length;
    for(int i=0;i<x.size();i++){
        for(int j=i+1;j<x.size();j++){
            _road=road(i,j,d,x);
            for(int _i=0;_i<_road.size();_i++)
                length.push_back(_road[_i].size());
            int min=length[0];
            std::vector<std::vector<int>> min_list;
            for(int _i=0;_i<length.size();_i++){
                if(min>length[_i]){
                    min=length[_i];
                    min_list.push_back(_road[_i]);
                    min_list.clear();
                }
                if(min==length[_i])
                    min_list.push_back(_road[_i]);
            }
            if(min_list.size()==1)
                return 0;
        }
    }
}
int main(){
    fstream read;
    read.open("migarate.in",ios_base::in);
    int c,t;
    read>>c>>t;
    std::vector<int> n(t),d(t);
    std::vector<vector<int>> x(t);
    for(int i=0;i<t;t++){
        read>>n[i]>>d[i];
        for(int j=0;j<n[i];i++)
            read>>x[i][j];
    }
    return 0;
}