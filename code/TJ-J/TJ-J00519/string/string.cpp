#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll jige;char zifu;
        cin>>jige>>zifu;

        while(jige--) s+=zifu;
    }
    string yyy=s;
    reverse(yyy.begin(),yyy.end());
    if(yyy==s)
    {
        cout<<0;
        exit(0);
    }
    ll len=s.size(),ans=0;
    for(ll i=0,j=len-1;i<len&&i>=0;i++,j--)
    {
        if(s[i]!=s[j]) ++ans;
    }
    cout<<ans/2;
	return 0;
}
