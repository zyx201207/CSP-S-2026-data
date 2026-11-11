#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum=0,ans=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    cin.ignore();
    for(ll i=1;i<=n;i++)
    {
        int x;
        string y;
        cin>>x>>y;
        sum+=x;
        for(ll j=1;j<=x;j++)
        {
            s+=y;
        }
    }
    for(ll i=0;i<sum/2;i++)
    {
        if(s[i]!=s[sum-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
