#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n;
long long m,a[N],ans,d[N],cnt,sum[N];
bool isA;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        if(i>=3&&a[i] - a[i-1] != a[i-1] - a[i-2]) isA=true;
        sum[i] = sum[i-1] + a[i];
    }
    if(isA==false) {
        int k=a[2]-a[1];
        int j=1;
        while(m-(long long)k*j >= 0) {
            m-=(long long)k*j;
            j++;
            ans++;
        }
        printf("%lld\n",ans+1);
        return 0;
    } else if(n<=5000) {
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) {
            cnt=0;
            for(int j=i-1;j>=1;j--) {
                cnt+=(long long) a[i] - a[j];
                if(cnt>m) break;
                d[i] = i-j+1;
            }
        }
        for(int i=1;i<=n;i++) {
            ans = max(ans,d[i]);
        }
        printf("%lld\n",ans);
    } else {
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) {
            int l=1,r=i-1;
            while(l<=r) {
                int mid = l+r>>1;
                if(sum[i-1]-sum[mid-1] + m >= a[i]*(r-mid+1)) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            d[i] = i - l + 1;
        }
        for(int i=1;i<=n;i++) {
            ans = max(ans,d[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
