#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,num,l = 0,bi = 0,ans = 0;cin>>n;
    char word;
    string s = "";
    for(int i=1;i<=n;i++) {
        cin>>num>>word;
        l += num;
        for(int j=1;j<=num;j++) s += word;
    }
    for(int i=l-1;i>=0;i--){
        if(s[i] != s[bi]) ans++;
        bi++;
    }

    cout<<ans/2;
    return 0;
}
