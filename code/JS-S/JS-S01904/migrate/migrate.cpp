#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,t,n,l[5005],r[5005],dis[5005][5005],cnt[5005];
ll d,a[2000005];
void solve1(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
            r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(l[j]<=i)dis[i][j]=1;
                else dis[i][j]=dis[i][l[j]]+1;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;++i){
            int mn=2,is=r[i],it=r[r[i]];
            for(int j=1;j<=n;++j)cnt[j]=j*(j<=is);
            for(int j=is+1;j<=n&&j<=it;++j){
                cnt[j]=cnt[j-1]+cnt[is]-cnt[l[j]-1];
                if(cnt[j]-cnt[j-1]==2)++ans;
                if(j==it)is=it,it=r[it],++mn;
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>t;
    solve1();
    return 0;
}