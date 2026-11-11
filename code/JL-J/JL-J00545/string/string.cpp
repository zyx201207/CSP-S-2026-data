#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=200000+10;
ll n,temlen,slen,cnt;
string s;
char tem;
ll is_hw(string s){
    double telen=(slen-1)/2;
    ll len=floor(telen);
    for(int i=0;i<=len;i++){
        if(s[i]!=s[slen-i]){
            return i;
        }
    }
    return -1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temlen>>tem;
        for(int j=1;j<=temlen;j++){
            s+=tem;
        }
    }
    slen=s.size()-1;
    ll i=0;
    while(is_hw(s)!=-1){
        if(s[i]!=s[slen-i]){
            s[slen-i]=s[i];
            cnt++;
        }
        i++;
    }
    cout<<cnt;
    return 0;
}
