#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e8+5;
ll n,a[200005],sa,qwq[MAXN],cur=0;
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        fill(qwq+cur+1, qwq+cur+a[i]+1, i);
        cur+=a[i];
        sa += a[i];
    }
    ll l=1,r=sa,cnt=0;
    while(l!=r && (l%2==0 ? 1 : (l != (sa/2+1)))){
        if (c[qwq[l]] != c[qwq[r]]) cnt++;
        l++;r--;
    }
    cout << cnt << endl;
    return 0;
}