#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;

int c,t;
ll x[N];
ll s[N];
int n;

bool work(ll u,ll v){
    s[1] = u,s[n] = v;
    int idx = 2;
    for(int i = 1;i <= n && i != u && i != v;i ++){
        s[idx ++] = i;
    }

    bool flag = 0;
    while(1){
        for(int i = 1;i <= n;i ++)

        bool b = next_permutation(s + 2,s + n);
        if(!b) break;
    }

    return flag;

signed main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> t;
    while(t --){
        ll n,d;
        cin >> n >> d;
        for(ll i = 1;i <= n;i ++){
            cin >> x[i];

        }

        ll ans = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = i + 1;j <= n;j ++){
                if(work(i,j)) ans ++;
        }

        cout << ans << '\n';
    }
    return 0;
}
