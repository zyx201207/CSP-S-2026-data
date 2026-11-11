#include <bits/stdc++.h>
using namespace std;
long c,t,n,d;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        vector<long> dao(n);
        for(long i=0;i<n;i++) {
            cin >> dao[i];
        }
        cout << (n&d)-1 << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
