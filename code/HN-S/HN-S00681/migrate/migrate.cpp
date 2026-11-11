#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
typedef pair<int,int>PI;
priority_queue<PI,vector<PI >,greater<PI > >q;
int C,T,n,D,ans,x[N],dis[N],vis[N],qq[N];
vector<int>e[N];
inline int read(){
    int sum=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        sum=sum*10+ch-'0';
        ch=getchar();
    }
    return sum*f;
}
void dij(int x){
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
        vis[i]=0;
        qq[i]=0;
    }
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i];
            int new_dis=dis[u]+1;
            if(dis[v]>new_dis){
                dis[v]=new_dis;
                q.push({dis[v],v});
            }
        }
    }
    return;
}
void solve(int u,int r,int sum){
    //cout<<u<<" "<<r<<" "<<sum<<"\n";
    if(sum>dis[u])return;
    if(u==r){
        ans++;
        return;
    }
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        solve(v,r,sum+1);
    }
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    C=read(),T=read();
    while(T--){
        n=read(),D=read();
        int f=1,bj,num;
        for(int i=1;i<=n;i++){
            x[i]=read();
            if(i>=2){
                num=x[i]-x[i-1];
                if(i==2)bj=num;
                else{
                    if(num!=bj)f=0;
                }
            }
        }  
        if(n>5000){
            int x=n-D-1;
            cout<<x<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int len=abs(x[i]-x[j]);
                if(len<=D){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dij(i);
                if(dis[j]==1)continue;
                solve(i,j,0);
               if(ans==2){   
                   res++;
               }
                ans=0;
            }
        }
        cout<<res<<"\n";
        for(int i=1;i<=n;i++)e[i].clear();
    }
    return 0;
}