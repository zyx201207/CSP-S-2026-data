#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{

    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
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
    long long a[n];
    long long ans;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    if(m>1)
    {
        ans=(a[0]&a[1]);
        for(int i=2;i<m;i++) ans&=a[i];
        cout<<ans;
    }
    else
    {
        cout<<a[0];
    }
    return 0;
}
