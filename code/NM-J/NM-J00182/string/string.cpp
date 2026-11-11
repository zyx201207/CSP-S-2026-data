//I AK CSP-J!!!
#include <bits/stdc++.h>
using namespace std;
int n,l=1,r;
long long ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int a;
        char c;
        cin >> a >> c;

        r += a;
        while(a){
            s += c;
            a--;
        }
    }
    string rs = s;
    reverse(rs.begin(),rs.end());
    if(s == rs){
        cout << 0;
        return 0;
    }
    int mid = l+(r-l) / 2;
    while(l != mid && r != mid){
        if(s[l] != s[r]) ans++;
        l++;
        r--;
    }
    cout << ans;

    return 0;
}
