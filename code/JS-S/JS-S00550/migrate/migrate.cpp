#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
vector<int> g[2000006];
int ans=0;
int minn=0x3f3f3f;
bool vis[2000006];
void dfs(int s,int t,int dis){
    if(s==t){
        if(minn==dis){
            ans++;
        }
        else if(minn>dis){
            minn=dis;
            ans=1;
        }
        return ;
    }
    for(int i=0;i<g[s].size();i++){
        if(vis[g[s][i]]==0){
            vis[g[s][i]]=1;
            dfs(g[s][i],t,dis+1);
            vis[g[s][i]]=0;
        }
    }
}
void solve(){
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int anss=0;
    for(int len=4;len<=n;len++){
        for(int s=1;s<=n-len+1;s++){
            int t=s+len-1;
            ans=0;
            dfs(s,t,0);
            if(ans==2){
                anss++;
            }

        }
    }
    cout<<anss<<endl;
    ans=0;
    minn=0x3f3f3f3f;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
