#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500100;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int ans=1,j=1;
    for (int i=2;i<=n;i++){
        m-=(a[i]-a[i-1])*(i-j);
        while (m<0 and j<i){
            m+=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    printf("%d\n",ans);
    return 0;
}
