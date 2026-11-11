#include <bits//stdc++.h>
int main()
{
	int n,m;
	std::cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		std::cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++)
		{
			cnt&=a[j+i];
		}
		sum=std::max(sum,cnt);
	}
	std::cout<<sum;
}
