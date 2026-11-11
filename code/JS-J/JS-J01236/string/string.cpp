#include<bits/stdc++.h>
using namespace std;
string s;
long long ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        int a;
        cin >> a >> c;
        for(int j = 1; j <= a; j++){
            s += c;
        }
    }
    int l = s.size();
    for(int i = 0; i < l/2; i++){
        if(s[i] != s[l-i-1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
