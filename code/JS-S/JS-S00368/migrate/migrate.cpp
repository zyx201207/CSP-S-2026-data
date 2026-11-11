#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e6 + 10 , INF = 1e18 , mod = 1e9 + 7;
int x[MAXN];
int c , t , n , d;
int calc(int i , int j){
    int res = 0;
    while(i < j){
        int l = i , r = j;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(x[mid] - x[l] <= d) l = mid;
            else r = mid - 1;
        }
        i = l;
        res++;
    }
    return res;
}
void solve(){
    cin>>n>>d;
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin>>x[i];
    }
    if(x[2] - x[1] == x[3] - x[2]){
        if(x[2] - x[1] >= d || x[n] - x[1] <= d) cout<<"0\n";
        else cout<<n - (d / (x[2] - x[1]) * 2 - 1)<<"\n";
    }
    else{
        int ans = 0;
        for(int l = 1 ; l < n ; ++l){
            int r = l + 1;
            if(x[r] - x[l - 1] <= d && x[r + 1] - x[l] <= d){
                if(r >= 4){
                    if(x[r] - x[l - 2] <= d) continue;
                }
                if(l <= n - 3){
                    if(x[r + 2] - x[l] <= d) continue;
                }
                int ls = 1 , rs = n;
                for(int i = l - 1 ; i >= 2 ; --i){
                    if(x[i] - x[i - 1] > d || x[i] - x[i - 2] <= d){
                        ls = i;
                        break;
                    }
                }
                for(int i = r + 1 ; i + 1 <= n ; ++i){
                    if(x[i + 1] - x[i] > d || x[i + 2] - x[i] <= d){
                        rs = i;
                        break;
                    }
                }
                if(ls == 1 && x[l] - x[ls - 1] <= d)
                cout<<l<<" "<<r<<" "<<ls<<" "<<rs<<"\n";
                ans += (rs - r) * (l - ls);
            }
        }
        cout<<ans<<"\n";
        for(int i = 1 ; i <= n ; ++i) x[i] = 0;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
