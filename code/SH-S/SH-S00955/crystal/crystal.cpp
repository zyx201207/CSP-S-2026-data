#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=500005;
long long n,m,a[maxn],s[maxn];

bool check(int x,int y) {
    if (a[y]*(y-x+1)-(s[y]-s[x-1])<=m) return 1;
    return 0;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=1,ans=0;
    while (r<=n) {
        if (check(l,r)) {
            ans=max(ans,r-l+1);
            r++;
        }else{
            l++;
        }
    }
    cout << ans;
}
