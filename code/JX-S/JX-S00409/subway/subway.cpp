#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=5e5+5;
const int maxd=20;

struct edge[
    ll u,v,w;
][maxm*maxd]
ll hall[maxm],num;
ll c,n,m,d,q;

void add(int u,int v,int w){
    ++num;
    edge[num].u=u;
    edge[num].v=v;
    edge[num].w=w;
    ++num;
    edge[num].v=u;
    edge[num].u=v;
    edge[num].w=w;
}
int main(){
    scanf("%d%d%d%d%d",c,n,m,d,q);
    for(ll i=1;i<=m;i++){
        ++num;
        cin>>hall[i];
    }
    for(ll i=1;i<=n;i++){
        ll k;
        ++num;
        cin>>k;
        for(ll i=1;i<=n;i++){
            ll a,t;
            cin>>a>>t;
            add(a,num,t);
        }
    }
    queue<int>q;
    q.push(&a);
    while(!q.empty()){

    }
