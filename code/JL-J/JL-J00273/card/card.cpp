#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long a[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	bool f=false;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0&&a[i-1]>a[i])f=true;
	}
	if(!f)
	{
		for(long long i=1;i<=m;i++)
		{
			
			long long cnt=0;
			for(long long k=i-1;k<n;k++)
			{
				if(a[k]==i)cnt=1;
			}
			if(i>1)cout<<' ';
			cout<<cnt;
		}
		cout<<'\n';
	}
	return 0;
}
