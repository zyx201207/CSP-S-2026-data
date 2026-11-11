#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],ans;
char c[100005];
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i <= n ; i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1; j <= a[i];j++)
        {
            s=s+c[i];
        }
    }
    ll len=int(s.size());
    for(int i=0; i <= len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
