#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a[500005],d[500005],s[500005];
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;++i)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1;i <= n;++i){
        int l = i + 1,r = n + 1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[mid] * (mid - i + 1) - (s[mid] - s[i - 1]) <= m)
                l = mid;
            else
                r = mid;
        }
        ans = max(ans,l - i + 1);
    }
    printf("%d\n",ans);
    return 0;
}
