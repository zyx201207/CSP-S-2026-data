#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,res;
int c[500010];
int a[500010],ind[500011];
bool cmp(int x,int y)
{
    return c[ind[x]]<c[ind[y]];
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i]-a[i-1];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,[&](int i,int j)->bool{
         return c[i]<c[j];
    });
    for(int i=1;i<=n;i++)
    {
        if(m>=abs(c[ind[i]]))m-=abs(c[ind[i]]),c[ind[i]]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==0)ans++;
        else res=max(res,ans),ans=0;
    }
    cout<<res;
    return 0;
}
