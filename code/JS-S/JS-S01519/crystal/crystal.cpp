#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ji,ans,jy;
ll m,a[500005],s,x;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1,jy=1;i<n;i++)
    {
        ji=1;
        if(s>0) s-=(jy-i+1)*(a[i-1]-a[i]),ji=jy-i+1;
        if(n-i+1<=ans) break;
        for(int j=jy+1;j<=n;j++)
        {
            x=a[i]-a[j];
            if(x<=m-s) ji++,s+=x;
            else
            {
                jy=j-1;
                break;
            }
        }
        ans=max(ans,ji);
    }
    cout<<ans<<endl;
    return 0;
}
