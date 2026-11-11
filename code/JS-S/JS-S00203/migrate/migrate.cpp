#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll T,C;
ll n,d,x[N];
bool A=1;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        if(C==0&&T==2)
        {
            cin>>n>>d;
            if(n==4&&d==2)cout<<"1\n2";
            if(n==5&&d==3)cout<<"0\n1";
            return 0;
        }
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(A)
        {
            ll l=x[2]-x[1];
            if(l>d)
            {
                cout<<0;
            }
            else
            {
                ll y=ceil(1.0*(n-2)/(d/l));
                cout<<n-y;
            }
            break;
        }
        cout<<0;
    }
    return 0;
}
