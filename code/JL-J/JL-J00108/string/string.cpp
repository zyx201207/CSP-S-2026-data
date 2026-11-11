#include<bits/stdc++.h>
using namespace std;
long long n,len,ans=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int i=0;i<a;i++) s+=c;
    }
    len=s.size();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-1-i]) ans++;
    }
    cout<<ans;
    return 0;
}
