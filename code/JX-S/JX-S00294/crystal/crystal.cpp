include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,x,cnt=0;
    long long o,p,l,y,max;
    cin>>n,m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j,=n;j++)
        {
            if(a[j]<a[i])
            {
                o=a[i];
                p=a[j];
                a[i]=p;
                a[j]=o;
            }
            if(a[j]==a[i])
            {
                l=a[i+1];
                y=a[j];
                a[i+1]=y;
                a[j]=l;
            }
        }
    }
    for(int z=1;z<=m;i++)
    {
        a[1]=a[1]+1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j,=n;j++)
            {
                if(a[j]<a[i])
                {
                    o=a[i];
                    p=a[j];
                    a[i]=p;
                    a[j]=o;
                }
                if(a[j]==a[i])
                {
                    l=a[i+1];
                    y=a[j];
                    a[i+1]=y;
                    a[j]=l;
                }
            }
        }
    }
    if(a[1]!=a[2])
    {
        cnt=2;
        cout<<cnt;
    }
    else
    {
        max=a[1]+a[2];
        cnt++;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==max)
            {
                max=max+a[i];
                cnt++;
            }
        }
        cout<<cnt+1;
    }
    return 0;
}
