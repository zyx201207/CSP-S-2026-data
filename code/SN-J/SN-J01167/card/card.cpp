#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300003;
long long n,m,a[N],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int s=1;
	while(s<=n)
	{
		for(int i=s;i<=n;i++)
		{
			cnt[a[i]]++;
			bool f=false;
			for(int j=s;j<=i-1;j++)
			{
				if(f)
				{
					cnt[a[j]]--;
				}
				if(a[j]==a[i])
				{
					cnt[a[i]]--;
					f=true;
				}
			}
		}
		s++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
