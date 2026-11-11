#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long b=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		long long k=a[i];
		for(int j=i+1;j<=m;j++)
		{
			k=k&a[j+i];	
		}
		if(k<b)
		{
			b=k;
		}
	}
	cout<<b;
	return 0;
}
