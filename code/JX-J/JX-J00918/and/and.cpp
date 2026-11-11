#include<bits/stdc++.h>
using namespace std;
int long long a,b,c[600000],d[600000],e,n[6000000],q=1,m=1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>n[i];
    }
    sort(n,n+a+1);
    while(n[a]>0)
    {
        c[q]=n[a]%2;
        n[a]=n[a]/2;
        q++;
    }
    for(int i=1;i<b;i++)
    {
        while(n[a-i]>0)
        {
            d[m]=n[a-i]%2;
            n[a-i]=n[a-i]/2;
            m++;
        }
        for(int j=1;j<=q;j++)
        {
            if(c[j]=d[j])
            {
                c[j]=1;
            }
            else{
                c[j]=0;
            }
        }
        for(int j=1;j<=m;j++)
        {
            d[j]=0;
        }
        m=1;
    }
    int long long sum=0,w=1;
    for(int i=1;i<q;i++)
    {
        if(c[i]==1)
        {
            for(int j=2;j<=i;j++)
            {
                w=w*2;
            }
            sum+=w;
        }
        w=1;
    }
    cout<<sum;
    return 0;
}
