#include<bits/stdc++.h>
using namespace std;
int n;
long long len=0,ans=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        char b;
        cin>>a>>b;
        len+=a;
        for(int i=1;i<=a;i++)s+=b;
    }
    if(n==1){cout<<0;return 0;}
    for(int i=0;i<=(len>>2)+1;i++){
        if(s[i]!=s[len-i-1]&&i<=len-i-1)
            ans++;
    }
    cout<<ans;
    return 0;
}
