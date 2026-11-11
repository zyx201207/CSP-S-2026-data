#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,ans;
vector<char> ve; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int wasd;
		char wasdc;
		cin>>wasd>>wasdc;
		for(int j=1;j<=wasd;j++)
		{
			ve.push_back(wasdc);
		}
		l+=wasd;
	}
	for(int i=0;i<l/2;i++)
	{
		if(ve[i]!=ve[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
