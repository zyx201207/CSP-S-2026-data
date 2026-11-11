#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[200005],d[35],f[35];
void wei(int q)
{
    int w=0;
    while(q)
    {
        if(q%2==1)d[w]++;
        w++;
        q/=2;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    f[0]=1;
    for(int i=1;i<=31;i++)f[i]=f[i-1]*2;
    int q,w,e,r;
    cin>>q>>w;
    for(int i=1;i<=q;i++)
    {
        cin>>c[i];
        wei(c[i]);
    }
    for(int i=31;i>=0;i--)if(d[i]<w)for(int j=1;j<=q;j++)
    {
        if(c[j]>=f[i])c[j]=c[j]-f[i];
    }
    sort(c+1,c+q+1,greater<int>());
    r=c[1];
    for(int i=2;i<=w;i++)r&=c[i];
    cout<<r;
}
