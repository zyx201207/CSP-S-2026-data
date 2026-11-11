#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int c,n,m,d,Q;
ll ans;
int w[1000007];
vector<pr>G[1000007];
vector<pr>a[507];
vector<pr>v[1000007];
int t1[500007],t2[500007];
ll dis[1000007];
priority_queue<pr,vector<pr>,greater<pr> >q;
void dij(int s){
    for(int i=1;i<=m;i++){
        dis[i]=1e18;
    }
    dis[s]=0;
    q.push(pr(0,s));
    while(!q.empty()){
        pr x=q.top();q.pop();
        int d=x.first,u=x.second;
        if(d>dis[u])continue;
        for(auto t:G[u]){
            int v=t.first,w=t.second;
            int now=w+dis[u];
            if(dis[v]>now){
                dis[v]=now;
                q.push(pr(dis[v],v));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),Q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int x=read();
        for(int j=1;j<=x;j++){
            t1[j]=read(),t2[j]=read();
            G[(t1[j]-1)*d+i+m].push_back(pr(t1[j],t2[j]));
            G[t1[j]].push_back(pr((t1[j]-1)*d+i+m,t2[j]));
            //a[i].push_back(pr(t1[j],t2[j]));
            if(j>=1){
                G[(t1[j-1]-1)*d+i+m].push_back(pr((t1[j]-1)*d+i+m,0));
                G[(t1[j]-1)*d+i+m].push_back(pr((t1[j-1]-1)*d+i+m,0));
            }
        }
    }
    while(Q--){
        int s=read(),t=read();
        dij(s);
        cout<<dis[t]+w[s]+w[t]<<"\n";
    }
    return 0;
}
