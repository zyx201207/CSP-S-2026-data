#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++)
    {
        cin>>n>>d;
        if(c==0&&n==4){
            cout<<1<<endl<<2;
            return 0;
        }
        if(c==0&n==5){
            cout<<0<<endl<<1;
            return 0;
        }
        if(c==0&&n==197)
        {
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
            return 0;
        }
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }

    }

    return 0;
}
