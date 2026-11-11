#include<bits/stdc++.h>
using namespace std;
const long long e=2e5+10;
long long a[e];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	#define int long long 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
		{
			cnt++; 
		}
	}
	if(cnt==n)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<0;
		}	
	}
	
	return 0;
}	
