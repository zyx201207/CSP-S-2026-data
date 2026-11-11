#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,f=0,w=0;
	int z[30];
	long long int sum=0,maxn=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[n]%2==a[n-1]%2)
		{
			sum=sum+k;
		}
		k=k*2;
		a[n]/=2;
		a[n-1]/=2;
		i++;
		w++;
	}
	cout<<sum;
	return 0;
}