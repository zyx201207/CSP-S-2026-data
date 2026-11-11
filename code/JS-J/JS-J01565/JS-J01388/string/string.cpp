#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    char a[3];
    char b = "";
    int c;
    char s = "";
    for (int i = 1; i<=n; i++){
        cin >> a;
        c = int(a[0]);
        b = char(a[2]);
        for (int j = 1; j<=c; j++){
            s += b;
        }
    }
    int l = s.len();
    int ans = 0;
    for (int k = 0; k<=(l/2)-1; k++){
        if (s[k] != s[l-k-1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
