#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005], cha[500005];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int ma = -1, mi = INT_MAX;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    int z = m;
    int ans = -1;
    for(int temp = mi; temp <= ma; temp++){
        z = m;
        //cout << "temp=" << temp << endl;
        memset(cha, 0x3f, sizeof(cha));
        for(int i = 1; i <= n; i++){
            if(temp - a[i] >= 0) cha[i] = temp - a[i];
            //cout << a[i] << " ";
        }
        bool f = 0;
        sort(cha + 1, cha + 1 + n);
        //cout << "cha: ";
        //for(int i = 1; i <= n; i++){
            //cout << cha[i] << " ";
        //}
        //cout << endl << "m:";

        for(int i = 1; i <= n; i++){
            //cout << "i=" << i << " ";
            z -= cha[i];
            if(z < 0 && f == 0){
                //cout << "answer =" << i - 1;
                ans = max(i - 1, ans);
                f = 1;
            }
            //cout << "z=" << z << " ";
        }
        if(!f) {
            cout << n;
            return 0;
        }
        //cout << endl;
    }
    cout << ans;
    return 0;
}
