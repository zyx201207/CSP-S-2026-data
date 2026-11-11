#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int yyw;
int A(int i,long long d)
{
    for(int j=1;j<i;j++)
    {
        if(x[j]+d+d-1==x[i])
        {
            return 1;
            yyw=j;
        }

    }
    return 0;
}
int B(int i,long long d)
{
    for(int j=yyw;j<i;j++)
    {
        if(x[j+1]-x[j]>d)
            return 1;
    }
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long d;
    int a,b,n;
    cin>>a>>b;
    while(b>0)
    {
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            x[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(A(i,d)==1)
            {
                if(B(i,d)==0)
                    ans++;
            }
        }
        b--;
        cout<<ans<<endl;
    }

    return 0;
}
