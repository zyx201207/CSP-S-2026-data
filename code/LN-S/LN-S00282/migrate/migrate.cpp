#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d;
    cin >> c >> t;
    while(t--){
        int num = 0;
        cin >> n >> d;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) for(int j = i; j < n; j++) if (a[j] - a[i] > d) num++;
        cout << (num + 1) / 2 << endl;//中庸之道
    }
    fclose(stdin);
    fclose(stdout);
    //看在我都进S组的份上，让我拿点分吧qwq luogu uid:1630835
    return 0;
}
