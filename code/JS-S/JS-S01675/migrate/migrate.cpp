#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while (t--){
        long long n,d,cnt=0;
        cin >> n >> d;
        long long x[n+5];
        for (long long i=1;i<=n;i++){
            cin >> x[i];

        }
        for (long long i=1;i<=n-3;i++){
            if (x[i+3]-x[i]>=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d)
                cnt++;
        }
        cout << cnt << endl;
    }


    return 0;
}
