#include <bits/stdc++.h>
using namespace std;
long long c,t,a;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int o=1;o<=t;o++)
    {
        long long n,d,x[200005];
        cin>>n,d;
        for(int i=d;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<n;i++)
        {
            long long minn[200005];
            for(int j=i;j<=n;j++)
            {
                minn[j]++;
            }
            a=max(minn[n]-4,4-minn[n]);
            if (a==0)
            {
                a=2;
            }
        }
        cout<<a<<endl;
    }
    return 0;
}


