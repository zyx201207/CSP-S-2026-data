#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
string s = " ";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while (n--){
        int a;
        char c;
        cin >> a >> c;
        while (a--){
            s += c;
        }
    }
    for (long long i = 1;i < s.size();i++){
        if (i > s.size() - i - 1){
            break;
        }
        if (s[i] != s[s.size() - i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
