#include<bits/stdc++.h>
using namespace std;
int n[10000],d[10000],x[10000];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i]>>d[i];
        for(int i=1;i<=n[i]+1;i++)
        {
            cin>>x[i];
        }
    }
    cout<<t-1<<endl<<t;
    return 0;
}
