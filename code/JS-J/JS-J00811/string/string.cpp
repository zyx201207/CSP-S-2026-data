#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
#define int long long
char c[N];
int n,a[N],ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
    for (int i = 1,j = n;i <= j;){
        if (a[i] < a[j]){
            a[j] -= a[i];
            if (c[i] != c[j]) ans += a[i];
            i++;
        } else if (a[i] == a[j]){
            if (c[i] != c[j]) ans += a[i];
            i++,j--;
        } else {
            a[i] -= a[j];
            if (c[i] != c[j]) ans += a[j];
            j--;
        }
    }
    printf("%lld\n",ans);
    return 0;
}