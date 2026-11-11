#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500010];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++) {
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+n+1);
    long long ans = 1,curst = 1,cursz = 1,last = m;
    for(int i = 2;i <= n;i++) {
        while(cursz * (arr[i] - arr[i-1]) > last) {
            last += (arr[i-1] - arr[curst]);
            curst++;
            cursz--;
        }
        last -= cursz * (arr[i] - arr[i-1]);
        cursz++;
        ans = max(ans,cursz);
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
