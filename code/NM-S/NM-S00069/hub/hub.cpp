#include <bits/stdc++.h>
using namespace std;
long c,t,n,d;
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        map<long,long> tree;
        for(long i=1;i<n;i++) {
            long a,b;
            cin >> a >> b;
            tree[a]=b;
            tree[b]=a;
        }
        cout << n/d-1 << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
