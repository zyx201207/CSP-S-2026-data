#include<bits/stdc++.h>
using namespace std;
int find(int a[],int n,int k,int s)
{
    for(int i=s;i<=n;i++)
    {
        if(a[i]==k)return i;
    }
    return 0;
}
void find1(int r,int t,int b[])
{
    for(int i=1;i<=t;i++)
    {
        if(b[i]==r)
        {
            b[i]=0;
        }
    }
}
int n,m,a[1000005],b[1000005],c[1000005],t,ans;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        t=n;
        for(int j=1;j<=n;j++)b[j]=a[j];
        for(int j=i;j<=n;j++)
        {
            int y=find(b,t,a[j],i);
            if(y==0)t++;
            else t=y;
            b[t]=a[j];
        }
        for(int j=i;j<=t;j++)
        {
            c[b[j]]++;
            find1(b[j],t,b);
        }
    }
    cout<<c[1];
    for(int i=2;i<=m;i++)cout<<" "<<c[i];
    return 0;
}
