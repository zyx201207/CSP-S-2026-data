#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[200001];
int er[31];
int v[200001];
int ans;
void erj(int x)
{
    int cnt=0;
    while(x)
    {
        er[cnt]+=x%2;
        x/=2;
        cnt++;
    }
}
int va(int x){
    int cnt=0;
    int val=0;
    int z=1;
    while(x)
    {
        if(er[cnt]>=m&&x%2)
            val+=z;
        z*=2;
        x/=2;
        cnt++;
    }
    return val;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
    }
    else if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            erj(a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            v[i]=va(a[i]);
        }
        sort(v+1,v+1+n);
        cout<<v[n-m+1];
    }

    return 0;
}
