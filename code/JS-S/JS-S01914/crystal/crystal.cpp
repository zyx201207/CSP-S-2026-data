#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll sum=a[1],cnt=1,ans=0,id=1;
    for(int i=2;i<=n;i++){
        ll x=(i-id)*a[i];
        if(x-sum>m){
            while(x-sum>m&&id<n){
                sum-=a[id];
                x-=a[i];
                id++;
            }
        }
        sum+=a[i];
        cnt=i-id+1;
        ans=max(cnt,ans);
    }
    printf("%lld",ans);
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
