#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int ans=a[i]&a[j];
			if(ans>mx) mx=ans;
		}
	}
	cout<<mx;
	return 0;
}
