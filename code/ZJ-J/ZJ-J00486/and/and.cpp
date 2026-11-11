#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,a[N];
int main()
{
	ifstream fin("and.in");
	ofstream fout("and.out");
	fin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
	}
	if(m==2)
	{
		int ans;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			if(i!=j)ans=max(ans,a[i]&a[j]);
		}
		fout<<ans;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		fout<<a[n];
	}
	if(m==n)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans&a[i];
		fout<<ans;
	}
	return 0;
}
