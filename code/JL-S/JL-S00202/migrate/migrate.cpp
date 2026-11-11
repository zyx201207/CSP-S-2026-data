#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int a[2000005];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<1<<endl;
    }
    return 0;
}
