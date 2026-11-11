#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,d;
int a[2000010];
int dis[2000010];
int cnt[2000010];
int ans=0;

void dfs(int x,int s){
    //cout<<x<<endl;
    if(s<dis[x]){
        dis[x]=s;
        cnt[x]=1;
    }else if(s==dis[x]){
        cnt[x]++;
    }else{
        return;
    }
    for(int i=x+1;a[i]-a[x]<=d&&i<=n;i++){
        dfs(i,s+1);
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int l=1;l<=n;l++){
            for(int i=l;i<=n;i++){
                dis[i]=1e18;
                cnt[i]=0;
            }
            dfs(l,0);
            for(int i=l;i<=n;i++){
                ans+=(cnt[i]==2);
                //cout<<i<<" :"<<cnt[i]<<endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
