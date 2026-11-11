#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
int n;
ll d;
ll x[N];
ll dis[N],cnt[N];
ll bl(int s){
    for(int i=s;i<=n;i++)dis[i]=1e18,cnt[i]=0;
    dis[s]=0;
    cnt[s]=1;
    ll ans=0;
    for(int i=s;i<=n;i++){
        if(cnt[i]==2)ans++;
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]>d)break;
            if(dis[j]>dis[i]+1){
                dis[j]=dis[i]+1;
                cnt[j]=cnt[i];
            }else if(dis[j]==dis[i]+1)cnt[j]+=cnt[i];
        }
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int csd,T;cin>>csd>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        ll ans=0;
        for(int i=1;i<=n;i++)ans+=bl(i);
        cout<<ans<<"\n";
    }
    return 0;
}

/*
10 21
0 7 14 21 28 35 42 49 56 63
*/