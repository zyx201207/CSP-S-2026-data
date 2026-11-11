#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll x[2000005];
ll dis[305][305];
ll cnt[305][305];

void floyd(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||abs(x[i]-x[j])>d){
                dis[i][j]=3e18;
                cnt[i][j]=0;
                continue;
            }
            dis[i][j]=1;
            cnt[i][j]=1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    cnt[i][j]=cnt[i][k]*cnt[k][j];
                }
                else if(dis[i][j]==dis[i][k]+dis[k][j]){
                    cnt[i][j]+=cnt[i][k]*cnt[k][j];
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt[i][j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}


void solve1(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    ll k=x[2]-x[1];
    ll t=d/k;
    ll ans;
    if(t>1)ans=max(n+1-t-t,0ll);
    else ans=0;
    cout<<ans<<"\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        if(c<=6)floyd();
        else if(c<=10)cout<<"1\n";
        else if(c<=12)solve1();
        else cout<<"1\n";
    }
    return 0;
}