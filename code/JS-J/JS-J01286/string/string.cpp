/*
CSP-J 2026 T2
Author:DFLJ

Passed it at 08:59
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    char ch;
    int l;
} a[200002],b[200002];
int s1[200002],s2[200002],n;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].l>>a[i].ch;
        b[i]=a[i];
    }
    reverse(b+1,b+n+1);
    for(int i=1; i<=n; i++)
    {
        s1[i]=s1[i-1]+a[i].l;
        s2[i]=s2[i-1]+b[i].l;
    }
    int id1=1,id2=1,j=1,ans=0,las=0;
    s2[n+1]=1e18;
    for(int i=1; i<=n; i++)
    {
        while(s2[j]<=s1[i])
        {
            ans+=(s2[j]-las)*(a[i].ch!=b[j].ch);
            las=s2[j];
            //cout<<las<<' '<<ans<<'\n';
            j++;
        }
        ans+=(s1[i]-las)*(a[i].ch!=b[j].ch);
        las=s1[i];
    }
    cout<<ans/2;
    return 0;
}
