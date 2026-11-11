#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int x[N],y[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)y[i]=y[i-1]+x[i];
    int l=1,ans=1;
    for(int i=1;i<=n;i++){
        while(l<=i&&x[i]*(i-l+1)-(y[i]-y[l-1])>m)l++;
        ans=max(ans,i-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}
//Igunareo ver.