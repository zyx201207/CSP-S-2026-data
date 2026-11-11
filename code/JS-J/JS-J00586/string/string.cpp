#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,cnt=0;
char c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    cin >> n;
    //
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(ll j=1;j<=a;j++){
            s+=c;
        }
    }
    //
    for(ll i=0,j=s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }
    //
    cout << cnt;
    //
    return 0;
}
