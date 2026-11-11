#include<bits/stdc++.h>
using namespace std;
long long n,m,x,b[500010],a[500010],summax,sum,MAX=-100000000010,MIN=1000000000010;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    x=m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>MAX)
        {
            MAX=a[i];
        }
        if(a[i]<MIN)
        {
            MIN=a[i];
        }
    }
    sort(a+1,a+n+1);
    for(int i=MIN;i<=MAX;i++)
    {
        for(int j=1;j<n;j++)
        {
            b[j]=a[j+1]-a[j];
        }
        for(int j=1;j<n;j++)
        {
            if(m-b[j]>=0)
            {
                sum++;
                m-=b[j];
            }else
            {
                m=-1;
            }
            if(m<0)
            {
                break;
            }
        }
        if(sum>summax)
        {
            summax=sum;
        }
        sum=0;
        m=x;
    }
    cout<<summax+1 ;
    return 0;
}
