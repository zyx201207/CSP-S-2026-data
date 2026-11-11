#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        int fa=1;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) fa=0;
        }
        if(fa==1)
        {
            long long x=a[2]-a[1];
            int p=d/x;
            if(p==0||p==1||p*2>n) cout<<0;
            else cout<<n-(p*2)+1;
            cout<<'\n';
            continue;
        }
        else
        {

            cout<<n/d;
        }
    }
    return 0;
}
