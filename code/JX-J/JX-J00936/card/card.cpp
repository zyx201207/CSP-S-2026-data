#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m,r,a[MAXN],v[MAXN],pos[MAXM],ans[MAXM];
bool asx=true,cz[MAXN];
inline void mn(int x)
{
    for(int i=1;i<=m;i++) cz[i]=false;
    r=0;
    for(int i=x;i<=n;i++)
    {
        if(cz[a[i]])
        {
            for(int j=pos[a[i]];j<=r;j++) cz[v[j]]=false;
            r=pos[a[i]]-1;
        }
        cz[a[i]]=true,r++,v[r]=a[i],pos[a[i]]=r;
    }
    for(int i=1;i<=m;i++)
        if(cz[i]) ans[i]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) asx=false;
    }
    if(m==1) cout<<n;
    else if(asx)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cz[j]=false;
            for(int j=i;j<=n;j++)
                if(!cz[a[j]]) cz[a[j]]=true,ans[a[j]]++;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    }
    else
    {
        for(int i=1;i<=n;i++) mn(i);
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    }
    return 0;
}
