#include<bits/stdc++.h>
using namespace std;
#define int long long

int t1;
char t2;
int n;
int ans = 0;
string s = "";
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t1 >> t2;
        for(int j = 0;j < t1;j++){
            s += t2;
        }
    }
    //cout << s;
    for(int i = 0;i <= s.size() / 2;i++){
        if(s[i] != s[s.size() - i + 1]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
