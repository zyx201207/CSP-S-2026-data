#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],c[500050],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=n;i>0;i--)
    {
        for(int j=i;j>0;j--)
        {
            b[i]=b[i]+(a[i]-a[j]);
            c[i]++;
            if(b[i]>m)
            {
                c[i]--;
                continue;
            }
        }
    }
    for(int i=n;i>=0;i--)
    {
        if(ans<=c[i])
            ans=c[i];
    }
    cout<<ans;
    return 0;
}
