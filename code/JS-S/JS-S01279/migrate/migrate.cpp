#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6+5;

int c,t;
int n;
ll d;
ll x[N];

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        ll di[n+5],ans = 0,cnt[n+5];
        for(int i=1;i<=n;i++)cin >> x[i];
        for(int i=1;i<=n;i++){
            ll last  = i;
            cnt[i] = 1,di[i] = 0;
            for(int j=i+1;j<=n;j++)cnt[j] = 0,di[j] = 1e18;

            for(int j=i+1;j<=n;j++){
                last = lower_bound(x+1,x+1+n,x[j] - d) - x;
                last = max(last,i*1ll);
                if(x[j]-x[last]<=d){

                    for(int k = last;k<j;k++){
                        if(di[j] > di[k] + 1){
                            di[j] = di[k] + 1;
                            cnt[j] = cnt[k];
                        }else if(di[j] == di[k] + 1){
                            cnt[j] += cnt[k];
                        }
                        //cout << i << " " << k << " " << j << " " << cnt[k] << '\n';
                    }


                }
                if(cnt[j] == 2) ans++;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
