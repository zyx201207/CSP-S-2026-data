#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long m,n,ans=0,a[1000010];
cin>>n>>m;
for(int i=0;i<=n-1;i++)
    cin>>a[i];
sort(a,a+n);
if(m==2)
    {
    for(int i=0;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++)
            ans=max(ans,a[j]&a[i]);
    cout<<ans;
    }
else if(m==3)
    {
    for(int i=0;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++)
            for(int q=j+1;q<=n-1;q++)
                ans=max(ans,(a[j]&a[i])&a[q]);
    cout<<ans;
    }
else if(m==4)
    {
    for(int i=0;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++)
            for(int q=j+1;q<=n-1;q++)
                for(int t=q+1;t<=n-1;t++)
                    ans=max(ans,((a[j]&a[i])&a[q])&a[t]);
    cout<<ans;
    }
else if(m==5)
    {
    for(int i=0;i<=n-1;i++)
        for(int j=i+1;j<=n-1;j++)
            for(int q=j+1;q<=n-1;q++)
                for(int t=q+1;t<=n-1;t++)
                    for(int z=t+1;z<=n-1;z++)
                        ans=max(ans,(((a[j]&a[i])&a[q])&a[t])&a[z]);
    cout<<ans;
    }
else if(m==1)
    cout<<a[n];
return 0;
}
