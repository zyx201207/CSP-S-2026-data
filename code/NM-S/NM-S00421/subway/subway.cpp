#include<bits/stdc++.h>
using namespace std;
bool contains(const std::vector<int>& data,int d){
    for(int i=0;i<data.size();i++)
        if(data[i]==d)return true;
    return false;
}
vector<int> node;
//line b to subway a time
vector<vector<int>> line_time;
//j in i
vector<vector<int>> connect_line;
vector<int> start;
vector<int> e;
int rep_time(int subway,int line_a,int line_b){
    return line_time[subway][line_b]+line_time[subway][line_a];
}
std::vector<int> kx_b(int star,int en){
    std::vector<int> ret;
    for(int i=0;i<connect_line.size();i++){
        if(contains(connect_line[i],star)&&contains(connect_line[i],star))ret.push_back(i);
    }
    return ret;
}
std::vector<int> has(int data){
    std::vector<int> ret;
    for(int i=0;i<connect_line.size();i++)
        if(contains(connect_line[i],data))
            ret.push_back(i);
    return ret;
}
int __oper(int star,int en,int _line){
    //none
    if(contains(connect_line[_line],en))return 0;
    std::vector<int> line=has(star);
    int min=-1;
    for(int i=0;i<line.size();i++){
        int _min=-1;
        for(int j=0;j<connect_line[line[i]].size();j++){
            int oper=__oper(connect_line[line[i]][j],en,line[i]);
            if(_min==-1)_min=oper;
            if(_min>oper)_min=oper;
        }
        _min+=rep_time(star,_line,line[i]);
        if(min==-1)min=_min;
        if(min>_min)min=_min;
    }
    return min;
}
int main(){
    fstream read;
    read.open("subway.in",ios_base::in);
    int c,n,m,d,q;
    read>>c>>n>>m>>d>>q;
    node.resize(m);
    for(int i=0;i<m;i++)
        read>>node[m];
    int k,j,l;
    read>>k;
    connect_line.resize(k);
    for(int i=0;i<k;i++){
        read>>j;
        connect_line[i].push_back(j);
        read>>l;
        line_time.resize(j);
        line_time[j].resize(i);
        line_time[j][i]=l;
    }
    start.resize(q);
    e.resize(q);
    for(int i=0;i<q;i++){
        read>>(start[i]);
        read>>(e[i]);
    }
    std::vector<int> result(q);
    for(int i=0;i<q;i++){
        std::vector<int> connect=has(start[i]);
        for(int j=0;j<connect.size();j++)
        result.push_back(__oper(start[i],e[i],j));
    }
    fstream write;
    write.open("subway.out",ios_base::out);
    for(int i=0;i<result.size();i++)
        write<<result[i];
    return 0;
}