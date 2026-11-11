

#include <iostream>
#include <algorithm>
using namespace std ;
const int N = 1e6+10;
long long a[N] ;
long long n , m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long ans = 1 ;
    for(long long l=1,r=1,cnt=0;l<=n;l++){
        while(cnt+(a[r+1]-a[r])*(r-l+1ll)<=m&&r<=n){
            cnt+=(a[r+1]-a[r])*(r-l+1ll);
            r++;
        }
        ans = max(ans,r-l+1);
        cnt-=(a[r]-a[l]);
    }
    cout << ans ;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

