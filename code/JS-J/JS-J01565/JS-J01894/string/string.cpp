#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
long long ans;
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
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(c[l]==c[r])
        {
            int x=min(a[l],a[r]);
            a[l]-=x;
            a[r]-=x;
        }
        else
        {
            int x=min(a[l],a[r]);
            a[l]-=x;
            a[r]-=x;
            ans+=x;
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans<<endl;
    return 0;
}
