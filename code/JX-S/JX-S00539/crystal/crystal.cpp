#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500050;
int n,ma;
ll m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    __int128 ans=0;
    for(int l=1,r=1;r<=n;r++){
        ans+=(r-l)*(a[r]-a[r-1]);
        while(ans>m&&r>=l) ans-=a[r]-a[l++];
        ma=max(r-l+1,ma);
    }
    printf("%d",ma);
    return 0;
}
