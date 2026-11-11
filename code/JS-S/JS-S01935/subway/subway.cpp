#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch;
    ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){ 
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int w[500005];
int n,m;
struct data{
    int u,v;
};
vector <data> a[500505];
int diss[505][500505];
int dis[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,p,q;
    c=read();
    n=read();
    m=read();
    p=read();
    q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int tmp;
        tmp=read();
        for(int j=1;j<=tmp;j++){
            int u,v;
            u=read();
            v=read();
            a[m+i].push_back({u,v});
            a[u].push_back({m+i,v});
        }
    }
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=1;i<=n;i++){
        memset(dis,0x3f,sizeof(dis));
        dis[m+i]=0;
        pq.push({0,m+i});
        while(!pq.empty()){
            int val=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            if(dis[x]<val) continue;
            // cout<<x<<endl;
            for(auto xx:a[x]){
                int uu=xx.u;
                int vv=xx.v;
                // cout<<uu<<" ";
                if(dis[uu]>dis[x]+vv){
                    dis[uu]=dis[x]+vv;
                    pq.push({dis[x]+vv,uu});
                }
            }
        }
        for(int j=1;j<=m;j++){
            diss[i][j]=dis[j];
        }
    }
    while(q--){
        int tmp1,tmp2;
        tmp1=read();
        tmp2=read();
        int ans=1e18;
        for(int i=1;i<=n;i++){
            ans=min(diss[i][tmp1]+diss[i][tmp2],ans);
        }
        cout<<ans+w[tmp1]+w[tmp2]<<endl;
    }
}
//16:20 O(qmlogm)
//17:10 O(nmlogm+nq) 