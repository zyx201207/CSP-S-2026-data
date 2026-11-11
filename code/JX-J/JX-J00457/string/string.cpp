#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        char b;
        cin>>a>>b;
        while(a--) s+=b;
    }
    int l=s.length();
    for(int i=0;i<l/2;++i){
        ans+=(!(s[i]==s[l-1-i]));
    }
    cout<<ans;
}
