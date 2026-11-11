#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,cnt,vis2[1000005],sum,ans;
bool vis[1000005];
vector<int> v[1000005];
void dfs(int now,int g){
    for(auto i:v[now]){
        if(vis[i-1])continue;
        if((g>>(i-1))&1){
            vis[i-1]=1;
            dfs(i,g);
        }
    }
}
void dfs2(int now){
    for(auto i:v[now]){
        if(vis2[i]>vis2[now]+1){
            vis2[i]=vis2[now]+1;
            dfs2(i);
        }
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        sum=INT_MAX;
        for(int i=0;i<(1<<n);i++){
            memset(vis,0,sizeof(vis));
            memset(vis2,-1,sizeof(vis2));
            cnt=0;
            for(int j=0;j<n;j++){
                if((1>>j)&1)cnt++;
            }
            if(cnt!=k)continue;
            cnt=0;
            for(int j=0;j<n;j++){
                if(((1>>j)&1)&&vis[j]!=1){
                    cnt++;
                    dfs(j,i);
                }
            }
            if(cnt>2)continue;
            cnt=0;
            for(int j=0;j<n;j++){
                if((1>>j)&1){
                    dfs2(j+1);
                }
            }
            ans=0;
            for(int j=1;j<=n;j++)ans=max(ans,vis2[j]);
            sum=min(sum,ans);
        }
        cout<<sum<<'\n';
    }
    return 0;
}
