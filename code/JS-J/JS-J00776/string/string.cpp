#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,ans,len; char c;
string s="";
int main(){
    freopen("string.in","r",stdin); freopen("string.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c; len+=a;
        for(int j=1;j<=a;j++) s=s+c;
    }
    for(int i=0;i<len/2;i++) ans+=int(s[i]!=s[len-i-1]);
    cout<<ans;
    return 0;
}
