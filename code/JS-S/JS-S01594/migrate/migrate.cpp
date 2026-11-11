#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N];
int Min[N], Ro[N], Gr[N];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> c >> t;
    while(t--){
        int ans = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            Min[i] = INT_MAX;
            Ro[i] = 1;
        }
        Min[1] = 0;
        Ro[1] = 1;
        Gr[1] = 1;
        int gr = 1;
        for(int i = 2; i <= n; i++){
            if(x[i] - x[i - 1] <= d){
                for(int j = i - 1; j >= 1 && x[i] - x[i - 1] <= d; j--){
                    Min[i] = min(Min[i], Min[j] + 1);
                }
                for(int j = i - 1; j >= 1; j--){
                    if(x[i] - x[j] <= d && Min[j] == Min[i] - 1)Ro[i] += Ro[j];
                }
            }
            else {
                Min[i] = 0;
                Ro[i] = 1;
                gr++;
                Gr[i] = gr;
                continue;
            }
            
            Gr[i] = gr;
        }
        for(int i = 1; i <= n - 1; i++){
            for(int j = i + 1; j <= n; j++){
                if(Gr[i] != Gr[j])break;
                if(Ro[j] / Ro[i] == 2)ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}