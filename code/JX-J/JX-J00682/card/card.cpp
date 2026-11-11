#include<bits/stdc++.h>
using namespace std;
long long n,m,d,cnt;
long long a[30005];
long long b[30005];
long long c[30005];
long long a1[30005];
long long b1[30005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        d=0;
        for(int j=i;j<n;j++)
        {
            d=max(d,a[j]);
            a1[j]=a[j];
            b1[a[j]]++;
            //cout<<b1[a[j]]<<" ";
            if(b1[a[j]]>1)
            {
                //cout<<a[j]<<" "<<c[a[j]]<<" ";
                for(int u=j-1;u>=c[a[j]];u--)
                {
                    a1[u]=0;
                    b1[a[u]]=0;
                }
                b1[a[j]]=1;
            }
            c[a[j]]=j;
        }
        for(int j=0;j<n;j++)
        {
            //cout<<a1[j]<<" ";
            b[a1[j]]++;
        }
        //cout<<endl;
        for(int j=0;j<n;j++)
        {
            b1[j]=0;
            c[j]=0;
            a1[j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<b[i+1]<<" ";
    }
    return 0;
}
