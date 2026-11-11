#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48),c = getchar();
    return f * x;
}
int n,m;
int a[N],sum[N],maxn;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    n = read(),m = read();
    for(int i=1;i<=n;i++)
        a[i] = read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i-1] + a[i];
    int tot = 0;
    for(int r=1,l=1;r<=n;r++){
        tot = (r - l + 1) * (a[r]) - (sum[r] - sum[l-1]);
        while(tot > m)
            l++,tot = (r - l + 1) * (a[r]) - (sum[r] - sum[l-1]);
        maxn = max(maxn, r - l + 1);
    }
    cout<<maxn<<'\n';
    return 0;
}