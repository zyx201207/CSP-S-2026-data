#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll a;
	char c;
	string str="";
	for (int i=0;i<n;i++)
	{
		cin>>a>>c;
		for (int i=0;i<a;i++)
			str.push_back(c);
	}
	int ans=0;
	for (int i=0;i<str.size()/2;i++)
		if (str[i]!=str[str.size()-i-1])
			ans++;
	cout<<ans;
	return 0;
}
