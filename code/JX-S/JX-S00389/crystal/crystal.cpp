#include <bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[50005], pref[50005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        pref[i] = pref[i - 1] + a[i];
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        if((i - 1) * a[i] - pref[i - 1] <= m){
            ans = i;
        }
        else{
            break;
        }
    }
    cout << ans;
    return 0;

}
