#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000020],ct,uv[2000020],sm;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        memset(x,0,sizeof x);
        memset(uv,0,sizeof uv);
        ct=sm=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n-2;i++)
        {
            if(x[i+3]-x[i+1]<=d&&x[i+2]-x[i]<=d)
            {
                uv[++ct]=i;
            }
        }
        uv[ct+1]=n-2;
        for(int i=1;i<=ct;i++)
        {
            int l=uv[i]-uv[i-1],r=uv[i+1]-uv[i];
            sm+=l*r;
        }
        cout<<sm<<"\n";
    }
    return 0;
}
