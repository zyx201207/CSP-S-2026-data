#include<bits/stdc++.h>
using namespace std;
int n,l=-1,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        int t;cin >> t;
        l+=t;
        char c;cin >> c;
        while(t--){
            s+=c;
        }
    }
    //cout << s << ' ' << floor(l*1.0/2) << ' ' << '\n';
    for(int i=0;i<=floor(l*1.0/2);i++){
            int j = l-i;
            if(s[i]!=s[j]){ ++ans;/*cout << i << ' ' << j << '\n';*/}
    }
    cout << ans;
    return 0;
}
