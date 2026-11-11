#include<bits/stdc++.h>

#define ll long long
using namespace std;
const ll N=5000+5;
int n;
ll d;
ll x[N];
ll ans;
bool vis[N];
bool g[N][N];
ll num[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int c,t;
cin>>c>>t;
while(t--){
cin>>n>>d;
for(int i=1;i<=n;i++)cin>>x[i];
for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
        if(x[j]-x[i]<=d)g[i][j]=true,g[j][i]=true;
    }
}
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++)vis[i]=false,num[i]=0;
    int l=i,r=i,now;
    for(int t=1;t<=n-i+1;t++){
            now=r;
            while(now<n&&g[l][now+1])now++;
            for(int k=l;k<=r;k++){
                for(int to=r+1;to<=now;to++){
                    if(g[k][to])num[to]++;
                }
            }
            l=r+1,r=now;
    if(now==n)break;
    if(!g[r][r+1])break;
    }
    //
    for(int qw=i+2;qw<=n;qw++)if(num[qw]==2)ans++;
    }
    cout<<ans<<'\n';
}
return 0;
}
