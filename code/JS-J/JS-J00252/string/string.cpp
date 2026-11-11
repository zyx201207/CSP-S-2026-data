#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005];
char c[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    ll ans=0;
    ll head=1,tail=n;
    ll l=a[head],r=a[tail];
    while (head<tail)
    {
        ans+=min(l,r)*(c[head]!=c[tail]);
        if (r>l)
        {
            r-=l;
            l=a[++head];

        }
        else
        {
            l-=r;
            r=a[--tail];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
