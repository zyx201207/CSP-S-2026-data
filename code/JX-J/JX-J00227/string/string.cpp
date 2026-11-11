#include <bits/stdc++.h>;
using namespace std;
#define ll long long
int n;
const int N=2e5+10;
ll a[N];
char c[N];
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int x=1,y=n;
    while(y-x>0)
    {
        if(c[x]!=c[y])
        {
            if(a[x]>=a[y])
            {
                ans+=a[y];
                a[x]-=a[y];
                y--;
                if(a[x]==0) x++;
            }
            else
            {
                ans+=a[x];
                a[y]-=a[x];
                x++;
            }
        }
        else
        {
            if(a[x]>=a[y])
            {
                a[x]-=a[y];
                y--;
                if(a[x]==0) x++;
            }
            else
            {
                a[y]-=a[x];
                x++;
            }
        }
    }
    cout<<ans;
    return 0;
}
