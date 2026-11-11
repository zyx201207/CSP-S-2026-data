#ihnclude<bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,d;
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i];
        }
        int s=a[n]-a[1];
        int sum=a[2]-a[1];
        int ans=s/sum;
        cout<<ans/d;
    }
}
