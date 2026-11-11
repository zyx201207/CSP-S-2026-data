#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,last,ans;
ll a[200010];

ll had[200010];

char c[200010];

int main( )
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(ll i = 1;i <= n;i ++)
        cin>>a[i]>>c[i];
    last = n;

    for(ll i = 1;i <= n;i ++)
    {
        if(a[i] != 0)
        {
            for(ll j = last;j >= 1;j --)
            {
                if(j == i)
                {
                    a[i] = 0;
                    break;
                }
                if(a[i] - a[j] > 0)
                {
                    if(c[i] != c[j])
                        ans += a[j];
                    a[i] -= a[j];
                }
                else if(a[i] - a[j] < 0)
                {
                    if(c[i] != c[j])
                        ans += a[i];
                    a[j] -= a[i];
                    a[i] = 0;
                    last = j;
                    break;
                }
                else if(a[i] - a[j] == 0)
                {
                    if(c[i] != c[j])
                        ans += a[i];
                    a[j] -= a[i];
                    a[i] = 0;
                    last = j + 1;
                    break;
                }
            }
        }
        else
            break;
    }

    cout<<ans;

    return 0;
}
