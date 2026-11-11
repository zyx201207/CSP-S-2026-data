#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,Max=-1,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long M=m;
	for(int i=1;i<=m;i++)
	{
		cnt=a[i];
		while(M)
		{
			M--;
			cnt=cnt and a[m];
		}
		if(Max<cnt)
		{
			Max=cnt;
		}
	}
	cout<<Max;
	return 0;
}