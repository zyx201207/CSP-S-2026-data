#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(long long i = 1;i<=n;i++){
        long long res = 0;
        long long ind = i-1;
        while(res<=m && ind>=1){
            res+=a[i]-a[ind];
            ind--;
        }
        if(res==m) ans = max(res,ans);
        else ans = max(res-(a[i]-a[ind+1]),ans);
        printf("%lld",ans);
    }
    printf("%lld",ans);
    return 0;
}
