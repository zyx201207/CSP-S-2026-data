#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN]={0},b[MAXN]={0},iex[MAXN]={0},ans;
bool cmp(int i,int j)
{
    if(b[i]==b[j])
    {
        return a[i]>a[j];
    }
    return b[i]>b[j];
}
int main()
{
    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        iex[i]=i;
        while(a[i]>0)
        {
            if(a[i]%2==1)
            {
                b[i]++;
            }
            a[i]/=2;
        }
    }
    sort(iex,iex+n,cmp);
    ans=a[iex[0]];
    for(int i=1;i<m;i++)
    {
        ans&=a[iex[i]];
    }
    printf("%lld",ans);
    return 0;
}
