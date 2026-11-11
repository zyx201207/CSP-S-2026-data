#include<bits/stdc++.h>
using namespace std;

long long a[10000000];

long long q[10000000];

long long pre[10000000];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,mx=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++)
	{
		q[i]+=abs(a[i+1]-a[i]);
		for(int j=1;j<=i;j++)
		{
			pre[i]+=q[j];
		}
	}
	for(long long i=1;i<n;i++)
	{
		for(long long j=i+1;j<n;j++)
		{
			if(pre[j]-pre[i]<=m)
			{
				mx=max(mx,j-i+1);
			}
		}
	}
	cout<<mx;
	return 0;
} 