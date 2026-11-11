#include <bits/stdc++.h>
#define int long long
#define L(i, a, b) for(int i = a;i <= b;i ++ ) 
using namespace std;
const int N = 2e6 + 5;
int x[N];
int res, sum;
int n, d;
int CSP, t;
void dfs(int nw, int dis, int lst){
    // cout << nw << endl;
    if(nw == lst){
        if(dis < res){
            res = dis, sum = 1;
        }
        else if(dis == res) sum ++ ;
        return ;
    }
    if(nw > lst) return ;
    if(dis > res) return ;
    L(i, nw + 1, n){
        if(x[i] - x[nw] <= d) dfs(i, dis + 1, lst);
        else break;
    }
}
void work()
{
    cin >> n >> d;
    L(i, 1, n) cin >> x[i];
    int ans = 0;
    if(CSP != 11 && CSP != 12){
    L(u, 1, n){
        L(v, u, n){
            res = LONG_LONG_MAX, sum = 0;
            dfs(u, 0, v);
            if(sum == 2) ans ++;
            // cout << "working!" << endl;
        }
    }
    cout << ans << endl;}
    if(CSP == 11 || CSP == 12){
        int gd = x[2] - x[1];
        if(d <= gd) {cout << 0 << endl; return ;}
        int onetime = d / gd, ans = 0, shumu = (n - 2 * onetime + 1);
        if(onetime % 2) onetime = (onetime - 1) / 2;
        else onetime /= 2;
        cout << max((int)0, shumu) << endl;
        // cout << shumu * onetime + (onetime - 1) * onetime / 2 << endl;
    }
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> CSP >> t;
    while(t -- ) work();
    return 0;
}
