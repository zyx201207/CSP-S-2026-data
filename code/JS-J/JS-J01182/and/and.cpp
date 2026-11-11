#include <bits/stdc++.h>
using namespace std;
long long n,m,x[200020],y[200020][32],ans = 0,p[32],t[33];
bool flag = 0;
void f(long long e,long long i){
    int te = 0,res = e;
    while (res){
        y[i][te] = res & 1;
        te++;
        res >>= 1;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> x[i];
        f(x[i],i);
    }
    p[0] = 1;
    for (int i = 1;i <= 31;i++) p[i] = p[i-1] * 2;
    for (int i = 31;i >= 0;i--){
        for (int j = 1;j <= n;j++){
            if (flag && !y[j][i+1]) {y[j][i] = 0;continue;}
            t[i] += y[j][i];
        }
        if (t[i] == m){
            int ttt = 0;
            for (int j = 1;j <= n;j++){
                if (y[j][i]){
                    if (ttt == 0) {ans = x[j];ttt = 1;}
                    else ans = (ans & x[j]);
                }
            }
            cout << ans;
            return 0;
        }
        if (t[i] > m) {ans += p[i];flag = 1;}
    }
    cout << ans;
    return 0;
}
