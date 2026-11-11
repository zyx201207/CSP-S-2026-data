#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,xs[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>xs[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+d+1;j<=n;j++){
                if(xs[j]-xs[i]>d&&j-i==3) {ans++;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}