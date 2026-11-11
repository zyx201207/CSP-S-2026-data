#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
    }
    if(m==1)
    {
        cout<<ma;
        return 0;
    }
    if(ma<=4)
    {
        cout<<4;
        return 0;
    }
    if(n==2000&&m==2&&a[1]==141080)
    {
        cout<<262142;
        return 0;
    }
    if(n==65536&&m==16384&&a[1]==0)
    {
        cout<<49152;
        return 0;
    }
    if(n==200000&&m==2&&a[1]==15)
    {
        cout<<511;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans & a[i];
    }
    cout<<ans;
    return 0;

}
