#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    while(n--){
        int a;
        string c;
        cin >> a >> c;
        while(a--) s += c;
    }
    ll len = s.size();
    ll mid = (len-1) / 2;
    ll ans = 0;
    for(int i=mid, j=mid; i>=0 && j<len; i--, j++){
        if(s[i] != s[j]) ans++;
    }
    cout << ans;
    return 0;
}
