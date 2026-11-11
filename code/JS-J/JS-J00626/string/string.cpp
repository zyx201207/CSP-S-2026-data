#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],len,ans;
char c[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    long long mid=len/2;
    long long l=1,r=len,cntl=1,cntr=n;
    while(l<r)
    {
        long long minn=min(a[cntl],a[cntr]);
        a[cntl]-=minn,a[cntr]-=minn;
        l+=minn,r-=minn;
        if(c[cntl]!=c[cntr]) ans+=minn;
        if(a[cntl]==0) cntl++;
        if(a[cntr]==0) cntr--;
    }
    cout<<ans;
    return 0;
}
