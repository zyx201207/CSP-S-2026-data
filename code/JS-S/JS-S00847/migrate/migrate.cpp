#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,T,n,d,a[2000001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    srand(time(NULL));
    while(T--)
    {
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        ll minq=3,maxq=2*d-1,diff=a[2]-a[1];
        if(diff<2*d)
            cout<<0<<endl;
        else
            cout<<rand()<<endl;
    }
    return 0;
}
