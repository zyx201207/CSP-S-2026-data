#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll INF=1e18;
ll c,T,n,m,a[N],d,dp[N],cnt[N];
vector<ll>q[N];
int main(){
    freopen("migrate3.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        ll ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i]=INF;
        }
        sort(a+1,a+n+1);
        for(int k=1;k<=n;k++){
            dp[k]=0;
            for(int i=k+1;i<=n;i++){
                ll l=k,r=i-1,mid,idx=i;
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(a[i]-a[mid]<=d){
                        idx=mid;
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
                for(int j=idx;j<i;j++){
                    if(dp[j]+1<dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=1;
                    }else if(dp[j]+1==dp[i]){
                        cnt[i]++;
                    }
                }
                if(dp[i]==0)break;
            }
            for(int i=1;i<=n;i++){
                cout<<cnt[i]<<" ";
                if(cnt[i]==2)ans++;
                dp[i]=INF,cnt[i]=0;
            }
            cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
