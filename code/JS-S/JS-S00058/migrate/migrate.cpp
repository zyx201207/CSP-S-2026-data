#include<bits/stdc++.h>
#define int long long

using namespace std;
int c,t;
int d,n;
int a[2000005];
int lst[2000005];
int twice[2000005];
int vis[2000005];
int num[2000005];
int nw;
queue<pair<int,int>>q;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int fis=1;fis<=n;fis++){
            lst[0]=fis;
            q.push(make_pair(fis,0));
            memset(twice,0,sizeof twice);
            memset(vis,0,sizeof vis);
            memset(num,0,sizeof num);
            while(!q.empty()){
                int u=q.front().first;
                int t=q.front().second;
                q.pop();
                for(int i=u+1;a[i]-a[u]<=d&&i<=n;i++){
                    if(!vis[i])num[i]=t+1;
                    if(num[i]!=t+1)continue;
                    vis[i]=vis[i]+vis[u];
                    if(vis[i]>2)continue;
                    else if(vis[i]=1)q.push(make_pair(i,t+1));
                }
            }
            for(int i=fis+1;i<=n;i++)if(vis[i]==2)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

