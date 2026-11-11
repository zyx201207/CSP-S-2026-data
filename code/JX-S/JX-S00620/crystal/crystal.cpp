#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m;
long long a[N];
long long cc[N];
int kans;
int as;
long long c[N];
int num;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        c[i] = a[i] - a[i - 1];
    }
    sort(a + 1, a + n + 1);
    if(n <= 5000){
        for(int l = 1;l <= n;l ++){
            int ans = 0;
            int cnt = 0;
            for(int i = l;i >= 1;i --){
                if(cnt + a[l] - a[i] <= m){
                    cnt += a[l] - a[i];
                    ans ++;
                    //cout << ans << "debugans" << " -------" << '\n';
                }
                else{
                    break;
                }
            }
            if(kans < ans){
                kans = ans;
            }
        }
        cout << kans << '\n';
    }
    if(a >= 5000){
        bool ex = 0;
        for(int i = 2;i < n;i ++){
            if(a[i] != i){
                ex = 1;
                break;
            }
        }
        if(!ex){
            for(int l = n;l >= 1;l --){
                if(m >= (n * (n - 1) / 2)){
                    cout << l << '\n';
                    break;
                }
            }
        }
        else{
            long long diff = c[2];
            for(int l = n;l >= 1;l --){
                if(m >= ((((l - 1)*diff)+diff) * (l - 1)) / 2){
                    cout << l << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}