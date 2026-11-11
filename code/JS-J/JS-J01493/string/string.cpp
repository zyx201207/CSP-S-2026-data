#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll a[200005];
char c[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	ll ans=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout << ans;
    return 0;
}
