#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",std.in);
    //freopen("and.out","w",std.out);
    long long a,b,c,d,e,f,ans;
    cin>>a>>b>>c>>d>>e>>f;
    if(d&&c>e&&d)
        ans=d&&c;
    if(d&&c<e&&d)
        ans=e&&d;
    if(e&&f>e&&d)
        ans=e&&f;
    if(e&&f<e&&d)
        ans=e&&d;
    if(b&&d>b&&e)
        ans=b&&d;
    if(b&&d<b&&e)
        ans=b&&c;
    if(b&&d>b&&e)
        ans=b&&d;
    if(b&&e>c&&f)
        ans=b&&e;
    if(b&&e<c&&f)
        ans=f&&c;
    if(b&&c>c&&d)
        ans=b&&c;
    if(b&&c>c&&d)
        ans=b&&c;
    cout<<ans;
    return 0;
}
