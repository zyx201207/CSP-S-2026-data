#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 2e5 + 7;
ll a[MAXN];
char c[MAXN];
//struct Info{
  //  int a;
    //char c;
//};
//stack <Info> st;
int main() {
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll k = n;
    ll ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    ll l = 1, r = n;

    while(l < r) {
            //cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<"\n";
        if(c[l] != c[r]) ans += min(a[l], a[r]);
        int xx = min(a[l], a[r]);
        a[l] -= xx, a[r] -= xx;
        if(a[l] <= 0) l++;
        if(a[r] <= 0) r--;
    }
    cout << ans << endl;
    /*
    for(int i = 1; i <= n; i++) {
        st.push({a[i],c[i]});
        for(int j = k; j >= 1; j--) {
            if(st.size()) {
                int da = st.top().a;
                char dc = st.top().c;
                if(!c[i] == dc) ans -= min(a[i], da);
                a[i] -= min(a[i], da);
                da -= min(a[i], da);

                if(a[i] <= 0) k--;
                st.pop();
                if(da > 0) st.push({da, dc});
            }
            else break;
        }
    }*/


    return 0;
}
