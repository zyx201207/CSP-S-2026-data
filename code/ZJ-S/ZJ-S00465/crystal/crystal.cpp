#include <bits/stdc++.h>
#define ll long long 
#define sc scanf 
#define pr printf
#define v1 first 
#define v2 second 
#define IINF 0x3f3f3f3f 
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;ll m;sc("%d%lld",&n,&m);
    for(int i=1; i <= n; i++)sc("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll sum=0;
    int ans=0;
    for(int i=1,l=1; i <= n; i++){
        sum+=a[i];
        while(l<i&&a[i]*(i-l+1)-sum>m){
            sum-=a[l];++l;
        }
        ans=max(ans,i-l+1);
    }
    cout << ans;
    return 0;
}