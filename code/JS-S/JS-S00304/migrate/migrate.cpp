#include<bits/stdc++.h>
using namespace std;
int c, T, n, t[500010];
long long a[500010];
long long d;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> T;
    while(T--){
        long long ans = 0;
        int mark = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int last = 1;
        while(a[last + 1] - a[1] <= d and last + 1 <= n){
            t[1] = last + 1;
            last++;
        }
        for(int i = 2; i <= n; i++){
            t[i] = t[i - 1];
            while(a[last + 1] - a[i] <= d and last + 1 <= n){
                last++;
                t[i] = last;
            }
            if(last == n and mark == 0){
                mark = i;
            }
        }
        //cout << ans << " ";
        //for(int i = 1; i <= n; i++){
        //    cout << t[i] << " ";
        //}
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(t[i] - i + 1 == 2){
                sum++;
            }
            else if(t[i] - i + 1 > 2 and t[t[i] - 1] <= mark){
                ans += (t[t[i] - 1] - t[i]) * (t[i] - 2 - i + 1);
                //cout << (t[t[i] - 1] - t[i]) * (t[i] - 2 - i + 1) << " ";
                sum = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
