#include<bits/stdc++.h>
using namespace std;
long long n,m,g,f[15005][15005],a[500005],c[500005],v;
long long ans=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","r",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
if(m>100000000)
{
    cout<<(a[1]+a[n])*n/2;
    return 0;
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=i;j++)
    {
        if(i==j)
        {
            f[i][j]=0;
        }
        else
        {
            f[i][j]=a[j]-a[i];
            f[j][i]=-f[i][j];
        }
    }
}
for(int i=2;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        while(f[i][j]<f[i-1][j])
        {
            swap(f[i][j],f[i-1][j]);
        }
    }
}
for(int i=1;i<=n;i++)
{
    int z=0,p=m,k=0;
    while(p>=0&&k<=n)
    {
        k++;
        if(p-f[k][i]>=0&&f[k][i]>=0&&z<n)
        {
            z++;
        }
            p-=f[k][i];
    }
    if(z>ans)
    {
        ans=z;
        v=p;
    }
}
if(ans==n&&v%n==0)
{
    cout<<ans;
    return 0;
}
cout<<--ans;

return 0;
}
