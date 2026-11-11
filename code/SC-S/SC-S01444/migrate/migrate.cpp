#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int inf = 1e9+7;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);
    int c, T; cin>>c>>T;
    while(T --){
        ll n, d; cin>>n>>d;
        vector<ll> s(n + 1);
        if(c == 11 || c == 12){
            for(int i=1;i<=n;i++){cin>>s[i];}
            ll dd = s[2] - s[1], t = d / dd;
            if(t < 2 || n < 2 * t){cout<<0<<"\n";}
            else{
                ll ans = 0;
                for(int i=1;i<=n;i++){
                    ans += ((i / t) - 1);
                }
                cout<<ans<<"\n";
            }
            continue;
        }
        vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
        for(int i=1;i<=n;i++){cin>>s[i];}
        for(int i=1;i<=n;i++){
            cnt[i][i] = 0;
            ll ct = 1, now = s[i];
            for(int j=i+1;j<=n;j++){
                if(s[j] - now > d){now = s[j - 1]; ct ++;}
                if(s[j] - now > d){ct = inf;}
                cnt[i][j] = ct;
            }
        }
        ll ans = 0;
        for(int i=n;i;i--){
            int j = n - 1;
            while(cnt[j][i] == 1){j --;}
            bool flg = false; int r = 0;
            for(;j;j--){
                ll ct = 0;
                for(int k=j+1;k<i;k++){
                    if(s[k] - s[j] > d){break;}
                    if(cnt[j][i] - cnt[k][i] == 1){ct ++;}
                }
                if((!flg && ct == 2) || (flg && ct == 2 && cnt[j][i] == r)){ans ++; flg = true; r = cnt[j][i];}
                else if((flg && ct == 1 && cnt[j][i] > r)){ans ++;}
                else if((flg && ct > 1 && cnt[j][i] > r) || (flg && ct > 2 && cnt[j][i] == r)){break;}
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}