#include<bits/stdc++.h>
using namespace std;
long long nn[500005];
long long nh[5005][5005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum=0,s=0,so=0,h=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        nn[i]=a;
        if(a!=nn[i-1])
        {
            s=1;
        }
        sum+=a;
        so++;
    }
    if(nn[n]-nn[n-1]==nn[n-1]-nn[n-3])
    {
        int cc=nn[n]-nn[n-1];
        long long jj=0;
        while(m>0)
        {
            jj++;
            m=m-jj*cc;
        }
        cout<<jj+1;
        return 0;
    }
    sort(nn+1,nn+1+n);
    if(s=0)
    {
        cout<<n;
        return 0;
    }
    else if(so<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1)
                {
                    nh[i][1]=0;
                }
                else{
                    nh[i][j]=nh[i][j-1]+nn[j]-nn[j-1];
                }
            }
        }
        long long max=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(nh[i][j]<=m)
                {
                    if(j-i>=max)
                    {
                        max=j-i;
                    }
                }
            }
        }
        cout<<max;
    }

	return 0;
}
