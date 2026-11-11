#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,t,ans;
    long long d,x[200010];
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int t=x[2]-x[1];
        t=d/t;
        if(t<=1)
            cout<<"0"<<endl;
        else
        {
            t++;
            ans=n-t;
            cout<<ans<<endl;
        }
    }
    return 0;
}
