#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    cin >> n;
    string c,s="";
    for (int i=1; i<=n; i++) {
        cin >> a >> c;
        for (int j=1; j<=a; j++) {
            s += c;
        }
    }
    int l=0;
    int r=s.size()-1;
    int ans = 0;
    for (int i=1; i<=s.size()/2; i++) {
        if (s[l]==s[r]) ans+=0;
        else ans+=1;
        l+=1;
        r-=1;
    }
    cout << ans;
    return 0;
}
