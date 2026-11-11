#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int in() {
    int x = 0;
    bool f = false;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int n,m;
int a[500007];
int ma,mi;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=in(),m=in();
    for (int i=1; i<=n; i++) {
        a[i]=in();
    }
    sort(a+1,a+n+1);
    int la=0,x=0;
    int ans=0;
    for (int l=1,r=1; l<=n&&r<=n;) {
        la=a[r]-a[r-1];
        x=(r-l)*la+x;
        while (x+(r-l-1)*(a[r]-a[r-1])<=m&&r<=n) {
            x=(r-l-1)*(a[r]-a[r-1])+x;
            r++;
        }
        while (l<r&&x-(a[r]-a[l])>m){
            x=x-(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans-1;
    return 0;
}
/*
5 5 1 2 4 8 9
5 8 -3 -1 2 2 7
*/
