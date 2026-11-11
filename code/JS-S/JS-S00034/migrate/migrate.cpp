#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int arr[2000010],cnt[2000010][2];
bool flag[2000010];
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--) {
        memset(arr,0,sizeof arr);
        memset(cnt,0,sizeof cnt);
        memset(flag,0,sizeof flag);
        scanf("%lld%lld",&n,&d);
        for(int i = 1;i <= n;i++) {
            scanf("%lld",&arr[i]);
        }
        for(int i = 1;i <= n - 3;i++) {
            int x = arr[i],y = arr[i+1],z = arr[i+2],w = arr[i+3];
            if(abs(w - x) > d && abs(z - x) <= d && abs(w - y) <= d) flag[i+1] = flag[i+2] = 1;
        }
        cnt[1][0] = 1;
        cnt[n][1] = 1;
        for(int i = 2;i <= n;i++) {
            if(flag[i] == 1) cnt[i][0] = 1;
            else if(abs(arr[i] - arr[i-1]) <= d) cnt[i][0] = cnt[i-1][0] + 1;
            else cnt[i][0] = 1;
        }
        for(int i = n - 1;i >= 1;i--) {
            if(flag[i] == 1) cnt[i][1] = 1;
            else if(abs(arr[i+1] - arr[i]) <= d) cnt[i][1] = cnt[i+1][1] + 1;
            else cnt[i][1] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n - 1;i++) {
            if(flag[i] == 1 && flag[i+1] == 1) {
                ans += cnt[i-1][0] * cnt[i+2][1]
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
