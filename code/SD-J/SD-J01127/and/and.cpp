#include<bits/stdc++.h>
using namespace std;
long long a[100086];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,max=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			swap(a[i],a[j]);
		}
	}
	max=a[1];
	for(int i=2;i<=m;i++)
	{
		max=max&a[i];
	}
	cout<<max<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0; 
} 
