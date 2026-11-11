#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long k[500010];
long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        k[i]=k[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        if(i<=ans)break;
        for(int j=1;j<=i;j++){
            if(i-j+1<=ans)break;
            long long p=(i-j+1)*a[i]-k[i]+k[j-1];
            if(p<=m){
                if(i-j+1>ans)ans=i-j+1;
                break;
            }
        }

    }
    cout << ans<<"\n";
    return 0;
}
