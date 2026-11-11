#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e9+5;
int n,x,tot,mid;
char s[N],c;
ll ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>c;
        while (x--)
        {
            s[++tot]=c;
        }
    }
    if (tot==1)
    {
        cout<<0;
        return 0;
    }
    mid=tot/2;
    int l=1,r=tot;
    while (true)
    {
        if (l==mid+1)
            break;
        if (s[l]!=s[r])
            ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
