#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,k;
vector<int> g[1005];
int h[1005];
int f[1005];
int dis[1005];
int ans=INT_MAX;
void chek(int u,int l){
    f[u]=f[l];
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==l||h[g[u][i]]==0)continue;
        chek(g[u][i],u);
    }
    return ;
}
void dfs(int u,int l,int d){
    dis[u]=min(dis[u],d);
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==l)continue;
        dfs(g[u][i],u,d+1);
    }
    return ;
}
void ch(int m,int l){
    if(m==k){
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=1;i<=n;i++){
            if(h[i]==1&&f[i]==i){
                chek(i,i);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(h[i]==1&&f[i]==i){
                cnt++;
            }
        }
        if(cnt>2)return;
        memset(dis,127,sizeof dis);
        for(int i=1;i<=n;i++){
            if(h[i]==1){
                dfs(i,i,0);
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(dis[i],mx);
        }
        ans=min(mx,ans);
        return ;
    }
    for(int i=l;i<=n;i++){
        ch(m,l+1);
        h[i]=1;
        ch(m+1,l+1);
        h[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(g,0,sizeof g);
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(c==1){
            if(k==n)cout<<0<<'\n';
            else cout<<1<<'\n';
        }else{
            ch(0,1);
            cout<<ans<<'\n';
        }

    }
    return 0;
}

