#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,ans,l,r;
struct node
{
    int x;
    char c;
}a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
    }
    l=1; r=n;
    while(l<r)
    {
        if(a[l].x<a[r].x)
        {
            if(a[l].c!=a[r].c) ans+=a[l].x;
            a[r].x-=a[l++].x;
        }
        else if(a[l].x>a[r].x)
        {
            if(a[l].c!=a[r].c) ans+=a[r].x;
            a[l].x-=a[r--].x;
        }
        else if(a[l].x==a[r].x)
        {
            if(a[l].c!=a[r].c) ans+=a[l].x;
            r--; l++;
        }
    }
    cout<<ans;
    return 0;
}
// 1 2 3 4 5 6 7
