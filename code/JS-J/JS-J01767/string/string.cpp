#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,len=0;
    cin>>n;
    string s;
    while(n--)
    {
        ll c;
        char a;
        cin>>c>>a;
        while(c--)
        {
            len++;
            s+=a;
        }
    }
    ll ans=0;
    for (int i = 0;i<=(len/2)-1;i++)
        if(s[i]!=s[len-i-1])
            ans++;
    cout<<ans;
    return 0;
}
