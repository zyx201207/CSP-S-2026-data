#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long ans=0;
long long num=1073741823;
void ad(int l,int m)
{
    if(m==0)
    {
        ans=max(ans,num);
        return;
    }
    for(int i=l;i<=n-m+1;i++)
    {
        long long temp=num;
        num&=a[i];
        ad(i+1,m-1);
        num=temp;
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            num&=a[i];
        }
        ans=num;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,a[i]);
        }
    }
    else
    {
        ad(1,m);
    }
    cout<<ans<<endl;
    return 0;
}
