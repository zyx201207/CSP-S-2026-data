#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s="";
ll n,len,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        ll a;
        char c;
        cin>>a>>c;
        len+=a;
        while(a--)s=s+c;
    }for(int i=0;i<len/2;i++)if(s[i]!=s[len-i-1])ans++;
    cout<<ans;
    return 0;
}
