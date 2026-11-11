#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//scanf("%lld%lld",&a,&b);
//printf("%lld",a*b);

const ll N = 1e6+5;

vector<int> mapa[N];
ll n,m;
ll a[N];
ll cha[N];
ll dp[50005];

int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal4.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
    for(int i=1;i<n;i++){
        cha[i] = a[i+1]-a[i];
    }
//    for(int i=1;i<n;i++){
//        cout<<cha[i]<<' ';
//    }
    ll maxn = 0;
    ll sum = 0;
    for(ll i=1;i<n;i++){
        for(ll j=1;i+j<=n;j++){
            sum+=cha[i+j-1];
            if(sum>m){
                sum-=cha[i];
                i++;
                maxn = max(maxn,j-i+2);
            }
        }
    }
    cout<<maxn;
    return 0;
}
