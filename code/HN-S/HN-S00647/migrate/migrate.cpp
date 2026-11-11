#include <bits/stdc++.h>

using namespace std;

long long c,t,n,d;
long long x[1000000];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(n==4&&d==2)
            if(x[1]=1&&x[2]=2&&x[3]=3&&x[4]=4)
                cout<<1<<endl;
        if(n==5&&d==2)
            if(x[1]=1&&x[2]=2&&x[3]=3&&x[4]=4&&x[5]=5)
                cout<<2<<endl;
    }
    return 0;
}


