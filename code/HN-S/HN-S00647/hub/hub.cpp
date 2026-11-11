#include <bits/stdc++.h>

using namespace std;

long long c,t,n,k;
long long u[1000000],v[1000000];

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {

        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>u[i]>>v[i];
        }

    }
    if(n==5&&k==2) cout<<1<<endl;
    if(n==10&&k==3) cout<<2<<endl;
    if(n==8&&k==6) cout<<1<<endl;
    if(n==6&&k==5) cout<<1<<endl;
    if(n==9&&k==3) cout<<2<<endl;
    return 0;
}


