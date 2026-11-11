#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d,e,f=0,i;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(i=1;i<=a;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+a+1);
    long long l=1,m,r=c[a];
    while(l<r)
    {
        d=0;
        e=0;
        m=(l+r)/2;
        for(i=m;i>=1;i--)
        {
            d=d+c[m]-c[i];
            if(d>b)
            {
                break;
            }
            e++;
        }
        if(e>f)
        {
            f=e;
        }
    }
    cout<<f;
    return 0;
}
