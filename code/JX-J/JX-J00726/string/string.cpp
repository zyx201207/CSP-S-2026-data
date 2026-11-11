#include <bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s,b;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i<=n;i++){
        cin >> a>>b;
        for(int i  = 1 ; i<=a;i++){
            s+=b;
        }

    }
    long long l = 0,r = s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;

    }
    cout << ans;







return 0;




}
