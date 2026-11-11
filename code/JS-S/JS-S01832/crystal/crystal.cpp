#include <bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
long long a[N], chaf[N], qz[N];
long long n, m, ans, sum;
int main(){
    freopen("cryctal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    sort (a+1, a+n+1);
    chaf[0] = 0;
    chaf[1] = a[1];
    qz[1] = a[1];
    ans = 1;
    for (int i = 1; i < n; i++){
        chaf[i+1] = a[i+1]-a[i];
        qz[i+1] = qz[i]+a[i+1];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            long long P = i-j+1;
            sum = qz[i]-qz[j-1];
            long long maxn = qz[i]-qz[i-1];
            double xba = (sum+m)/P;
            if((sum%P+m%P)%P == 0 && (double)maxn <= xba){
                ans = max(ans, P);
            }
        }
    }
    cout << ans;
    return 0;
}
