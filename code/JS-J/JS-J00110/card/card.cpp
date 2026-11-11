//I often racall the past QaQ T^T
//wo chang chang zhui yi guo qu
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
using ll=long long;


ifstream fin("card.in");
ofstream fout("card.out");

int tag[maxn];
int to_rank[maxn];
int to_node[maxn];
int deep[maxn];
int fa[maxn];
int last[maxm];
int nodesize=0;


vector<int>son[maxn];
int symbol[maxn];


ll ans[maxm];
ll dfs(int node){
    ll total=tag[node];
    for(auto nxt:son[node]){
        total+=dfs(nxt);
    }
    ans[symbol[node]]+=total;
    return total;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i = n-1;i >= 0;i--){
        cin>>a[i];
    }

    for(int i = 0;i <= n; i++) tag[i] = deep[i] = last[i] = 0;
    for(int i = 0;i <= n; i++)fa[i]=0;

    int nownode=0;
    for(int i=0;i<n;i++) {
        if(last[a[i]] != 0){
            nownode = to_node[to_rank[last[a[i]]]-1];
            tag[nownode]++;
        }
        else {
            int addr = ++nodesize;
            to_rank[addr]=i;
            to_node[i]=addr;
            son[nownode].push_back(addr);
            fa[addr] = nownode;
            symbol[addr] = a[i] ;
            last[symbol[addr]] = addr;
            nownode=addr;
            tag[nownode]++;
        }
    }

    dfs(1);
    for (int i = 1 ; i <= m ; i++)cout<<ans[i]<<" ";
}