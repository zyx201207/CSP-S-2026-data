#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500010];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    bool flagA = true;
    int prevstep;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if (i==1){
            prevstep = a[1]-a[0];
        }

        if (i>1 && a[i]-a[i-1] != prevstep){
            flagA = false;
        }
    }

    if (flagA){
        int ans = 0;
        while(ans*(ans+1)*prevstep/2 <= m && ans < n){
            ans++;
        }
        cout << ans;
        return 0;
    }

    sort(a, a+n);
    int ans = 1;
    for(int i = 0; i<n; i++){
        int ansi = 1, mm = m;
        while(mm >= 0 && i-ansi>=0){
            mm -= a[i] - a[i-ansi];
            ansi++;
        }
        if (mm<0){
            ansi--;
        }
        if(ansi > ans){
            ans = ansi;
        }
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
