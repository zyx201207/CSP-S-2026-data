#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    long long l=1,r=1;
    long long ad=0,ans=0;
    for(r=1;r<=n;r++)
    {
        if(r>l)
        {
            ad+=(r-l)*b[r];
        }
        while(ad>m)
        {
            ad-=a[r]-a[l];
            l++;
        }
        ans=max(r-l+1,ans);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
