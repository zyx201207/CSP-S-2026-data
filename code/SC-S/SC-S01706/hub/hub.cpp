#include<bits/stdc++.h>
const int N=1e6+11;
using namespace std;
int c,t;
int n,k;
vector<int> v[N];
int vis[N],book[N],dist[N];
void dfs(int x){
    vis[x]=1;
    for(int i=0;i < (int)v[x].size();i++){
        int y=v[x][i];
        if(!book[y]||vis[y]) continue;
        dfs(y);
    }
}
void dfs2(int x,int fa){
    for(int i=0;i < (int)v[x].size();i++){
        int y=v[x][i];
        if(y==fa) continue;
        dist[y]=min(dist[y],dist[x]+1);
        dfs2(y,x);
    }
}
int maxN,st;
void dfs3(int x,int fa,int P){
    if(P>maxN){
        st=x;
        maxN=P;
    }
    for(int i=0;i < (int)v[x].size();i++){
        int y=v[x][i];
        if(y==fa) continue;
        dfs3(y,x,P+1);
    }
}
void dfs4(int x,int fa,int P){
    if(P>maxN){
        maxN=P;
    }
    for(int i=0;i < (int)v[x].size();i++){
        int y=v[x][i];
        if(y==fa) continue;
        dfs4(y,x,P+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i <= n;i++) v[i].resize(0);
        for(int i=1;i < n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n<=10){
            int ans=0x3f3f3f3f;
            for(int i=0;i < (1<<n);i++){
                int cnt=0;
                for(int j=1;j <= n;j++){
                    book[j]=0,vis[j]=0,dist[j]=0x3f3f3f3f;
                    if((i>>j-1)&1){
                        dist[j]=0;
                        cnt++;
                        book[j]=1;
                    }
                }
                if(cnt!=k) continue;
                cnt=0;
                for(int j=1;j <= n;j++){
                    if(book[j]&&!vis[j]){
                        cnt++;
                        dfs(j);
                    }
                }
                if(cnt>2) continue;
                for(int j=1;j <= n;j++){
                    if(book[j]){
                        dfs2(j,0);
                    }
                }
                int maxN=0;
                for(int j=1;j <= n;j++){
                    maxN=max(maxN,dist[j]);
                }
                ans=min(ans,maxN);
            }
            cout<<ans<<"\n";
        }else{
            maxN=0,st=1;
            dfs3(1,0,0);
            maxN=0;
            dfs4(st,0,0);
            if(maxN%3==0){
                cout<<maxN/3<<"\n";
            }else{
                cout<<maxN/3+1<<"\n";
            }
        }
    }
    return 0;
}