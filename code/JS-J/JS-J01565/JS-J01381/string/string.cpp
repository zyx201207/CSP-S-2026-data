#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll ar[500005];
ll p[500005];
ll bgn[500005];
char br[500005];
string s = "";
ll l = 0;

ll func(ll a){
    return l+1-a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin >> n;
    repe(i,1,n){
        cin >> ar[i] >> br[i];
        l += ar[i];
    }
    if(l <= 1e3 && n <= 50){
        repe(i,1,n){
            repe(j,1,ar[i]) s += br[i];
        }
        ll ans = 0;
        rep(i,0,s.length()/2){
            if(s[i] != s[s.length()-i-1]){
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    repe(i,1,n) p[i] = p[i-1] + ar[i];
    p[0] = 0;
    repe(i,1,n){
        bgn[i] = p[i-1]+1;
    }
    ll ans = 0;
    repe(i,1,n){
        ll start = p[i-1]+1,end = min(l/2,p[i]);
        ll rstart = func(start),rend = func(end);// rend < rstart
        ll rStIdx = lower_bound(p+1,p+1+n,rend)-p,rEdIdx = lower_bound(p+1,p+1+n,rstart)-p;
        #ifdef LOCAL
        cout << "i:" << i << '\n';
        cout << start << ' ' << end << '\n';
        cout << rstart << ' ' << rend << '\n';
        cout << rStIdx << ' ' << rEdIdx << '\n';
        #endif
        repe(j,rStIdx,rEdIdx){
        #ifdef LOCAL
            cout << "j:" << j << '\n';
        #endif
            if(br[i] == br[j]) continue;
            if(bgn[j] <= rend && p[j] >= rstart){
                ans += ar[i];
            }else if(bgn[j] <= rend){
        #ifdef LOCAL
                cout << "1:\n";
                cout << rend << '_' << p[j] << '\n';
        #endif
                ans += p[j]-rend+1;
            }else if(p[j] >= rstart){
        #ifdef LOCAL
                cout << "2:\n";
                cout << (p[j-1]+1) << '_' << rstart << '\n';
        #endif
                ans += rstart-(p[j-1]+1)+1;
            }else{

        #ifdef LOCAL
                cout << "3:\n";
                cout << (p[j-1]+1) << '_' << p[j] << '\n';
        #endif
                ans += ar[j];
            }
        }
        #ifdef LOCAL
        cout << "ans:" << ans << '\n';
        #endif
        if(p[i] >= l/2) break;
    }
    cout << ans;
    return 0;
}

/*
5
1 a
3 b
1 c
2 d
2 a

4
1 a
1 b
1 c
3 d

*/