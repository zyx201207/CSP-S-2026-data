#include<bits/stdc++.h>
#define uint long long
using namespace std;
uint n;
constexpr uint N=5e5+5;
uint a[N],b[N];
uint m;
uint c;
uint slv=0;
bool flg=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(uint i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i!=1)
        {
            if(i==2)
            {
                c=a[i]-a[i-1];
            }
            else
            {
                if(a[i]-a[i-1]!=c)
                {
                    flg=false;
                }
            }
        }
    }
    if(flg==true)
    {
        for(uint i=1;i<=n;i++)
        {
            slv+=c*i;
            if(slv==m)
            {
                cout << i+1;
                return 0;
            }
            if(slv>m)
            {
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    for(uint i=n;i>=1;i--)
    {
        if((i-1)*a[i]-b[i-1]<=m)
        {
            cout << i;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
