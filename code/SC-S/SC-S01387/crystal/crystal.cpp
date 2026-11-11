#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],dp[500001];
int main()
{
	freeopen("crystal.in","r",stdin);
	freeopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int q=1;q<=n;q++)
	{
		cin>>a[q];
	}
	for(int q=1;q<n;q++)
	{
		for(int w=q+1;w<=n;w++)
		{
			if(a[q]>a[w])swap(a[q],a[w]);
		}
	}
	for(int q=2;q<=n;q++)
	{
		dp[q]=(a[q]-a[q-1])*(q-1)+dp[q-1];
	}
	int answer;
	for(int q=1;q<=n;q++)
	{
		if(m>=dp[q])answer=q;
		else break;
	}
	cout<<answer;
	return 0;
}