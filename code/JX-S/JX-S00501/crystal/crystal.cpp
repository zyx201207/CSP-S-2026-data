#include <iostream>
#include <algorithm>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    if(a[1] < 0){
        long long o = a[1];
        for(int i = 1; i <= n; i ++) a[i] += o;
    }
    for(int i = 1; i <= n; i ++){
        b[i] = b[i - 1] + a[i];
    }
    for(int i = 2; i <= n; i ++){
        c[i] = (i - 1) * a[i] - b[i - 1];
    }
    int ans = -1;
    int l = 1;
    long long q = 0;
    long long p = a[1];
    for(int i = 2,res = 1; i <= n; i ++){
        p = c[i] - (long long)(l - 1) * a[i] + (long long)q;
        res = res + 1;
        while(p > m && l <= n) {
            p = p + a[l] - a[i],q = q + a[l],l = l + 1,res = res - 1;
        }
        ans = max(res,ans);
    }
    cout << ans << endl;
    return 0;
}
