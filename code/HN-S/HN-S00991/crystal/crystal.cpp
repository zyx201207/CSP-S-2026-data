#include<bits/stdc++.h>

using namespace std;
const int N=500000;
int n,Ans;
long long m,a[N+10],b[N+10],maxx;

long long Abs(long long x)
{
    return x<0?-x:x;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            b[j]=abs(a[i]-a[j]);
        
        sort(b+1,b+1+n);
        for(int j=1;j<=n;j++)
        {
            b[j]=b[j-1]+b[j];
            if(b[j]<=m)Ans=max(Ans,j),maxx=max(maxx,b[j]);
        }
        
    }
    cout<<Ans<<'\n';
    return 0;
}