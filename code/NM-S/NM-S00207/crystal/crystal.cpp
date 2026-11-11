#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int m;
int a[100000005]={},b[100000005];


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int minn=1e9,maxn=-1e9,ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        b[i]=x;
        if(x>=maxn) maxn=x;
        if(x<=minn) minn=x;
    }
    for(int i=minn;i<=maxn;i++)
    {
        a[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        a[b[i]]++;
    }
    for(int i=minn;i<=maxn-m;i++)
    {
        int sum=0;
        for(int j=i;j<=i+m;j++)
        {
            sum+=a[j];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
