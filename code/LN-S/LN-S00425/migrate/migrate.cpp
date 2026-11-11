#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
long long f(long long i,long long j){
    long long k = i,ans = 1;
    for (long long a = i;a <= j;a++)
        if (x[a+1]-x[k]>d){
            ans++;
            k = a;
        }
    return ans;
}
bool check(long long i,long long j){
    for (long long a = i;a <= j;a++)
        if (x[a+1]-x[i] > d)
            if (f(a-1,j)==f(a,j))
                return true;
            else
                return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cin >> c >> t;
    while (t--){
        long long ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
            cin >> x[i];
        for (int i = 1;i <= n;i++)
            for (int j = i+1;j <= n;j++)
                if (check(i,j))
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}
