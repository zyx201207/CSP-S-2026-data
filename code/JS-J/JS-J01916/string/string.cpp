#include <bits/stdc++.h>
using namespace std;
struct str
{
    long long x;
    char c;
}a[200005];
long long n,ans,l,r;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
    }
    l=1,r=n;
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            if(a[l].x<a[r].x)
            {
                a[r].x-=a[l].x;
                l++;
            }
            else if(a[l].x>a[r].x)
            {
                a[l].x-=a[r].x;
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            if(a[l].x<a[r].x)
            {
                a[r].x-=a[l].x;
                ans+=a[l].x;
                l++;
            }
            else if(a[l].x>a[r].x)
            {
                a[l].x-=a[r].x;
                ans+=a[r].x;
                r--;
            }
            else
            {
                ans+=a[l].x;
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
