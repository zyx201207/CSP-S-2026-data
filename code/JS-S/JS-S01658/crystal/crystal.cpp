#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n,ans = 1;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) s[i] += s[i-1]+a[i];
    int l = 1,r = 2;
    while(r <= n){
        ll p = (r-l)*a[r]-(s[r-1]-s[l-1]);
        if(p > m) l++;
        else ans = max(ans,r-l+1),r++;
    }
    cout << ans;
    return 0;
}
/*5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
