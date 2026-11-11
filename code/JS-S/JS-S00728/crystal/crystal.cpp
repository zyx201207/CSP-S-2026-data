#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=500005;
int n;
ll m;
ll a[M];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll cost=0;
    int ans=1;
    ll lst=a[1];
    for(int i=1,l=1;i<=n;i++){
        cost+=(i-l)*(a[i]-lst);
        while(cost>m){
            cost-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
        lst=a[i];
    }
    printf("%d\n",ans);
    return 0;
}