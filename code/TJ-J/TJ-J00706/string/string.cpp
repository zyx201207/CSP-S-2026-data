#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,a,sum=0,ans=0;
	string c,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	for(int i=0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i-1])
			ans++;
	}
	
	cout<<ans;
	
	return 0;
} 
