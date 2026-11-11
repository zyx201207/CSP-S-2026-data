#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500666;
int n,ans;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++){
        ll L=0,R=i+1,M=(i+1)/2;
        for (;L+1<R;M=(L+R)/2){
            if (a[i]*M<=m+s[i]-s[i-M]) L=M;
            else R=M;
        }
        ans=max(ans,(int)L);
    }
    printf("%d\n",ans);
    return 0;
}
