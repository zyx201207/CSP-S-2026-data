#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen(and.in,"r",stdin);
freopen(and.out,"w",stdout);
	int n,m,max;
	max=0;
	cin>>n>>m;
	int a[100001];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i+=m)
	{
		int sum=0;
		for(int j=0;j<=m;j++)
		{
		sum+=(a[i+j] and a[i+j+1]);
		}
		if(sum>max)
		{
			max=sum;
		}
	}
	cout<<max<<endl;
	return 0;
}
