#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
int chk(string x)
{
    ll l=x.size()-1,cnt=0;
    for(int i=0;i<l/2;i++)
        if(s[i]!=s[l-i]) cnt++;
    return cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n<=200000)
    {
        for(int i=1;i<=n;i++)
        {
            ll x;
            char a;
            cin>>x>>a;
            for(int j=1;j<=x;j++)
                s+=a;
        }
        cout<<chk(s);
    }
    return 0;
}
