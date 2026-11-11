#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans=0;
    string s=" ";
    int a;
    string c;
    cin >> n;
    while(n--){
        cin >> a >> c;
        while(a--){
            s+=c;
        }
    }
    int l=s.size()-1;
    for(int i=1;i<=l/2;i++){
        if(s[i]!=s[l-i+1]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}//expect 12*4+2*4+(3*4)=[56,68]