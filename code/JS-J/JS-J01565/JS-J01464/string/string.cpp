# include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
struct block{
    long long len;
    char type;
}s[MAX];
long long n, ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i].len >> s[i].type;
    }
    int fpi = 1, lpi = n;
    while (fpi < lpi){
        if (s[fpi].type != s[lpi].type) ans += min(s[fpi].len, s[lpi].len);
        if (s[fpi].len == s[lpi].len){
            fpi++;
            lpi--;
        }
        else if (s[fpi].len > s[lpi].len){
            s[fpi].len -= s[lpi].len;
            lpi--;
        }
        else{
            s[lpi].len -= s[fpi].len;
            fpi++;
        }
    }
    cout << ans;
    return 0;
}
