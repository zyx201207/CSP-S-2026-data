#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2*1e5+10;
ll a[N];
ll n,m;
ll dp[16377][16377];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    //memset(a,1,sizeof(a));

    ll ans=INT_MIN;
    if(m==1){
        for(ll i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }else if(m==n){
        ans=a[1];
        for(ll i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==n-1){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i==j) continue;
                else
                {
                    if(ans==INT_MIN) ans=a[j];
                    else ans&=a[j];
                }
            }
        }
        cout<<ans;
        return 0;
    }



    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(i==1) dp[i][j]=max(dp[i-1][j],a[j]);
            else if(j>=i) dp[i][j]=max(dp[i-1][j],a[j]&dp[i-1][j-1]);
        }
    }

    cout<<dp[m][n];






    /*for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    ll ans=a[n];
    for(int i=n-1;m>0;i--,m--){
        ans&=a[i];
    }

    cout<<ans;*/


    return 0;
}
