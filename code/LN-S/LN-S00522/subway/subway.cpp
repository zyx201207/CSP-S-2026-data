#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int pt[603];
vector<vector<pair<int,long long> > >a(603);
int read(){
    long long num=0;
    char c=getchar();
    while(c>='0' and c<='9'){
        num*=10;
        num+=(c-'0');
        c=getchar();
    }
    return num;
}
long long solve(int x,int y){
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> >>q;
    q.push({0,x});
    bool vis[603];
    for(int i=0;i<=600;i++)vis[i]=0;
    vis[x]=1;
    while(!q.empty()){
        pair<long long,int>p=q.top();
        q.pop();
        vis[p.second]=1;
        if(p.second==y)return p.first+pt[x]+pt[y];
        for(auto u:a[p.second])if(!vis[u.first])q.push({p.first+u.second,u.first});
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++)pt[i]=read();
    for(int i=1;i<=n;i++){
        int K;
        K=read();
        while(K--){
            int x=read(),y=read();
            a[x].push_back({m+i,y});
            a[m+i].push_back({x,y});
        }
    }
    while(q--){
        int x=read(),y=read();
        cout<<solve(x,y)<<endl;
    }
return 0;
}
