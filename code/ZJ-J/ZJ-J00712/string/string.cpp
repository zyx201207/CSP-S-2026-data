#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,num;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a,id;
		char k;
		cin>>a>>k;
		for(ll j=1;j<=a;j++)
		{
			s+=k;
		}
		num+=a;
	}
	for(ll i=0;i<num;i++)
	{
		if(s[i]!=s[num-i-1])
		{
			sum++;
		}
	}
	cout<<sum/2;
	return 0;
}
