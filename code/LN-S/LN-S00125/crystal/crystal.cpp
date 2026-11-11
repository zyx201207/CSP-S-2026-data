#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int an=1,su=0,lmx=0;;
    for(int i=1,j=1;i<=n;i++){
        int c=0;
        while(i<n&&a[i]==a[i+1])i++,c++;
        su+=(i-j-c)*(a[i]-lmx);
        while(su>m){
            su-=a[i]-a[j];
            j++;
        }
        an=max(an,i-j+1);
        lmx=a[i];
    }
    printf("%lld",an);
    return 0;
}
