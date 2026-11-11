#include<bits/stdc++.h>
using namespace std;
long long a[2000009];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int C,t;
    cin>>C>>t;
    while(t--)
    {
        int n;
        long long d;
        cin>>n>>d;
        //cout<<n<<" "<<d<<endl;
        long long c=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i==2) c=a[i]-a[i-1];
            else if(i>2)
            {
                if(c!=a[i]-a[i-1]) ok=0;
            }
        }
        if(ok==1)
        {
            if(d<=c) cout<<0;
            else
            {
                long long cnt=d/c;
                if(n<2*cnt-1) cout<<0;
                else cout<<n-cnt-cnt+1;
            }
            cout<<endl;
        }
    }
    return 0;
}
