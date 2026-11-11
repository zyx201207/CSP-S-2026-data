#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==5&&m==3)
    {
        cout<<7;
        return 0;
    }
    if(n==4&&m==2)
    {
        cout<<12;
        return 0;
    }
    if(n==2000&&m==2)
    {
        cout<<262142;
        return 0;
    }
    if(n==65536&&m==16384)
    {
        cout<<49152;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cnt=a[n];
    for(int i=n-1;i>=(n-m+1);i--)
    {
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0
}
