#include <bits/stdc++.h>;
using namespace std;
long long n,x,ans;
char ch;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> x >> ch;
        for (int j = 1;j <= x;j++){
            s+=ch;
        }
    }
    for (int i = 0;i < s.size()/2;i++){
        if (s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
