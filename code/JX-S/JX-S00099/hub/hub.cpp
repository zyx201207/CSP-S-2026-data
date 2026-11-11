#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;//kruskal / tarjan
vector<int>e[100005];
vector<int>e2[100005];/*
int num(int u,int v){
    for(int i=1;i<=n;++i){
        e2[i].push_back(e[i]);
        e2[e[i]].push_back(i);
    }
    e2[u].push_back(v);
    e2[v].push_back(u);


    return 0;
}*/
void finish_do(int n){
    for(int i=1;i<=n;++i){
        e[i].clear();
        e2[i].clear();
    }

}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    for(int numt=1;numt<=t;++numt){
        ll n,k;
        cin>>n>>k;
        for(int i=1;i<=n;++i){
            e[i].clear();
        }
        for(int i=1;i<=n;++i){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout<<abs((2*n-k*k)/k-1)<<"\n";
        finish_do(n);
    }
    return 0;
}
