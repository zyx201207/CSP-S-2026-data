#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll ans=0;
ll p[200005];
char g[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll k;
    char a;
    ll sum=0;
    p[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>k>>a;
        p[i]=p[i-1]+k;
        g[i]=a;
    }
    ll si=1,sj=n;
    char pi,pj;
    for(int i=1,j=n;i<=n,j>=1,i<=j;--j,++i)
    {

        if(g[i]!=g[j])
        {

            ll pi=p[i]-p[i-1],pj=p[j]-p[j-1];
            if(pi>pj)
            {

                ans+=pj;
                p[i]-=pj;
                i--;

            }
            else if(pi<pj)
            {

                ans+=pi;
                p[j]-=pi;
                j++;
            }
            else{
                ans+=pi;
            }
        }
    }
    cout<<ans;
    return 0;
}
