#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

ll a[N];
int n;
ll m;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n;i++){
       cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    ll ans = 0;
    for(int i = 1;i <= n;i++){
        ll target = a[i];
        ll tmp = m, cnt = 0;

        for(int j = 1; j <= n;j++){
            if(a[j] > target){
                continue;
            }
            if(a[j] == target){
                cnt++;
                continue;
            }

            if(tmp >= (target - a[j])){
                cnt++;
                tmp -= (target - a[j]);
            }else{
                break;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
