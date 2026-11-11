#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }
    for(int i=1;i<=s.length()/2;i++)
    {
        int tmp=n-i+1;
        if(s[i]!=s[tmp]) ans++;
    }
    cout<<ans;
    /*long long gap=0;
    for(int i=1;i<=n/2;i++)
    {
        int tmp=n-i+1;
        if(a[i]==a[tmp]&&c[i]==c[tmp]&&gap==0) continue;
        if(c[i]==c[tmp]) gap+=abs(a[i]-a[tmp]);
        else gap+=min(a[i],a[tmp]);
    }
    cout<<gap;*/
    return 0;
}
