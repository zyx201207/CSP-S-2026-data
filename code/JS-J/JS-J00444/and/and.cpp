#include<bits/stdc++.h>
using namespace std;
long long int num[33],n,w;
long long int a[210000],maxn=0,t=0;
void kk(long long int shuwei)
{
    memset(num,0,sizeof(num));
    for(long long int i=1;i<=n;i++)
    {
        long long int s=0;
        long long int m=a[i];
        while(m!=0)
        {
            num[s]=num[s]+m%2;
            s++;
            m=m/2;
        }
    }
    long long int shu=shuwei;
    for(shuwei=shu;shuwei>=0;shuwei--)
    {
        if(num[shuwei]>=w) break;
    }
    t=t+pow(2,shuwei);
    if(shuwei<=0)
    {
        cout<<t<<endl;
        return;
    }
    for(long long int i=1;i<=n;i++)
    {
        if(a[i]>=pow(2,shuwei))
        {
            long long int z=pow(2,shuwei);
            a[i]=a[i]%z;
        }
        else
        {
            a[i]=0;
        }
    }
    kk(shuwei-1);
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>w;
    for(long long int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    long long int shuwei=0;
    while(1==1)
    {
        if(pow(2,shuwei)>maxn)
        {
            break;
        }
        shuwei++;
    }
    kk(shuwei-1);
    return 0;
}
