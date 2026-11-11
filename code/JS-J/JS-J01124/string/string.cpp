#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string sz="",sf="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++)
            sz+=c[i];
    }
    for(int i=n;i>=1;i--)
        for(int j=0;j<a[i];j++)
            sf+=c[i];
    int s=sz.size(),ans=0;
    for(int i=0;i<s;i++)
        if(sz[i]!=sf[i])
            ans++;
    ans/=2;
    cout<<ans;
    return 0;
}
