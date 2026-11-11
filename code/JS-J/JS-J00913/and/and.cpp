#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2147483647,N=2e5+5,IN=(1<<50)-1;
ll maxx,n,m,dp[N];
vector<ll> a;
void dfs(ll ds,ll i,ll sum){
    if(ds>=m){
        maxx=max(maxx,sum);
        return;
    }
    if(m+i>ds+n){
        return;
    }
    if(i>=n){
        return;
    }
    dfs(ds+1,i+1,sum&a[i]);
    dfs(ds,i+1,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        ll x=0;
        cin>>x;
        a.push_back(x);
        dp[i]=IN;
    }
    if(min(abs(n-m),m)<=2){
        dfs(0,0,INF);
        cout<<maxx;
    }else{
        for(ll i=0;i<m;i++){
            for(ll j=n-1;j>=i;j--){
                if(dp[i]<=INF){
                    dp[i]=max(dp[i],(dp[j-1]&a[j]));
                }else{
                    dp[i]=(dp[j-1]&a[j]);
                }

            }
        }
        cout<<dp[m-1];
    }

    return 0;
}
