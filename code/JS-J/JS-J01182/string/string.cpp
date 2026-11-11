#include <bits/stdc++.h>
using namespace std;
long long s1[200020],n,s = 0,l = 1,r,t1 = 0,t2,ans = 0;
char s2[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;r = n;
    for (int i = 1;i <= n;i++){
        cin >> s1[i] >> s2[i];
        s += s1[i];
        s1[i] += s1[i-1];
    }
    t2 = s;
    if (n == 1){cout << 0;return 0;}
    while (t1 < t2 && l < r){
        if (s1[l] - t1 == t2 - s1[r-1]){
            if (s2[l] != s2[r]) ans += s1[l] - t1;
            t1 = s1[l];t2 = s1[r];
            l++;r--;
        }
        if (s1[l] - t1 < t2 - s1[r-1]){
            if (s2[l] != s2[r]) ans += s1[l] - t1;
            t2 -= (s1[l] - t1);t1 = s1[l];l++;
        }
        if (s1[l] - t1 > t2 - s1[r-1]){
            if (s2[l] != s2[r]) ans += t2 - s2[r-1];
            t1 += (t2 - s2[r-1]);t2 = s2[r-1];r--;
        }
    }
    cout << ans;
    return 0;
}
