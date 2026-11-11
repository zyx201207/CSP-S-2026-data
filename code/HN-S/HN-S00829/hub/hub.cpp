#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int S=1<<20;
int c,t;
int n,k;
int dp[S];
int num;
bool vis[N];
bool vis2[N];
vector<int> tr[N];
void dfs(int u,int fa){
    vis[u]=true;
    for(auto v:tr[u]){
        if(v==fa){
            continue;
        }else{
            if(vis[v])continue;
            dfs(v,u);
        }
    }
}
void dfs2(int numm,int u,int fa,int zd){
    if(u==zd){
        num=numm;return;
    }
    for(auto v:tr[u]){
        if(v==fa)continue;
        dfs2(numm+1,v,u,zd);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int a,b;
            // vis[i]=vis2[i]=false;
            cin>>a>>b;
            tr[a].push_back(b);
            tr[b].push_back(a);
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<(1<<n);i++){
            int tmp=i,cnt=0,pos=0;
            vector<int> dian;
            for(int j=1;j<=n;j++){
                vis2[j]=false;
            }
            while(tmp){
                if(tmp&1){
                    dian.push_back(pos+1);
                    cnt++;
                    vis2[pos+1]=true;
                }
                tmp>>=1;
                pos++;
            }
            if(cnt==k){
                int num=0;
                for(int j=1;j<=n;j++){
                    vis[j]=false;
                }
                for(auto poss:dian){
                    if(!vis[poss]){
                        num++;dfs(poss,0);
                    }
                }
                if(num>2)continue;
                int tmpans=0,tmpp=0x3f3f3f3f;
                for(int j=1;j<=n;j++){
                    tmpp=0x3f3f3f3f;
                    for(int k=1;k<=n;k++){
                        num=0;
                        if(vis2[j]){
                            continue;
                        }dfs2(0,j,0,k);
                        tmpp=min(tmpp,num);
                    }
                    tmpans=max(tmpans,tmpp);
                }
                ans=min(ans,tmpans);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}