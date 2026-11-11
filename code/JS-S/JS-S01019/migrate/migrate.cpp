#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long c,t,n,d,a[5005],r,ans,l,minl;
void dfs(long long x,long long y)
{
    //cout<<x<<" ";
    if(x==y)
    {
        minl=min(l,minl);
        //cout<<endl;
        return;
    }
    for(long long i=x;i+1<=y && a[i+1]-a[x]<=d;i++)
    {
        //cout<<i+1;
        l++;
        dfs(i+1,y);
        l--;
    }
}
void qr(long long x,long long y)
{
    if(x==y)
    {
        //cout<<l<<" ";
        if(l==minl)
            r++;
        return;
    }
    for(long long i=x;i+1<=y && a[i+1]-a[x]<=d;i++)
    {
        //cout<<i+1;
        l++;
        qr(i+1,y);
        l--;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(long long e=1;e<=t;e++)
    {
        ans=0;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
            cin>>a[i];
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
        {
            l=0;
            minl=5005;
            r=0;
            dfs(i,j);
            qr(i,j);
            //cout<<minl<<endl;
            if(r==2)
            {
                //cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
