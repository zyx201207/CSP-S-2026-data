#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const ll M=5e5+10;
ll a[M];
map<ll,ll>MP;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=5&&m<=2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(MP[a[j]])
                    mp[a[j]]=0,;
                MP[a[j]]++;
            }
        }
    }
    return 0;
}
//真是遗憾啊，我dp不会写了，不然稳切T3的……
