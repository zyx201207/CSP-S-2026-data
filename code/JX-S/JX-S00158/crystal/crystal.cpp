#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,ans;
long long m,a[N],d[N];
long long k=0,sum=0;
int tot=0;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    d[1]=a[1];
    for(int i=2;i<=n;i++)  d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
    {
        sum=0,k=0,tot=0;
        for(int j=i;j>=1;j--)
        {
            k+=d[j];
            if(sum+k<=m)
            {
                sum+=k;
                tot++;
            }
        }
        ans=max(tot,ans);
    }
    cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
