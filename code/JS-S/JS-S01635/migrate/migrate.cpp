#include<bits/stdc++.h>
using namespace std;
long long c,t,n,f;
long long d,k,h;
int ansx=0;
int ls[105];
long long a[2000006];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int j=1;j<=t;j++)
    {
        f=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=2;i<=n-1;i++)
        {
            if(a[i]-a[i-1]!=a[i+1]-a[i])
            {
                f=1;
                break;
            } 
        }
        if(f==0)
        {
            k=a[n]-a[n-1];
            h=d/k;
            if(h==1||h==0) cout<<0<<'\n';
            else if(n-2*h+1>=0) cout<<n-2*h+1<<'\n';
            else cout<<0<<'\n';
        }
    }
    return 0;
}