#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],c[1000005],d[1000005],sum;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        while(a[1]!=0)
        {
            c[sum]=a[i];
            sort(a+1,a+1+n);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<n<<a[5]<<a[1];
    }
}
