#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int inf=LONG_LONG_MAX/4;
const int N=1e6+10,RN=1e6;
int cid,T,n,d,ans;
int a[N];
int dis[N],cnt[N];
void solve(){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) dis[j]=inf,cnt[j]=0;
        dis[i]=0;
        cnt[i]=1;
        for(int j=i;j<=n;j++){
            if(cnt[j]==2) ans++;
            for(int k=j+1;k<=n;k++){
                if(a[k]-a[j]>d) break;
                if(dis[k]==dis[j]+1){
                    cnt[k]+=cnt[j];
                }
                else if(dis[k]>dis[j]+1){
                    dis[k]=dis[j]+1;
                    cnt[k]=cnt[j];
                }
            }
        }
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cid>>T;
    while(T--){
        solve();
    }
    return 0;
}