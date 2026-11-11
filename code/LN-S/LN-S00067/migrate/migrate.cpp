#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        int x[n+1];
        for (int i=1;i<=n;i++) cin >> x[i];
        int temp = x[2]-x[1];
        int s=0;
        s = n - int(d/temp) -1;
        cout << s << endl;
    }

    return 0;
}
