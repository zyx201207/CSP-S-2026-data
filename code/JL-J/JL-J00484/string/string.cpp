#include <bits/stdc++.h>
using namespace std;
int n,x,ans;
char c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(int j=1;j<=x;j++)
            s+=c;
    }
    int len=s.size();
    string sz="",sy="";
    for(int i=0;i<len/2;i++)
        sz+=s[i];
    for(int i=len/2;i<len;i++)
        sy+=s[i];
    for(int i=0;i<len/2;i++)
        if(sz[i]!=sy[i])
            ans++;
    cout<<s<<" "<<sz<<" "<<sy;
    cout<<ans;
    return 0;
}
