#include<bits/stdc++.h>
using namespace std;

const int N=5e5;
long long a[N+5],cnt[N+5],d[N+5];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=true;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) d[j]=-1;
		for(int j=i;j<=n;j++)
		{
			if(d[a[j]]!=-1)
			{
				for(int k=d[a[j]]+1;k<=j;k++)
				{
					d[a[k]]=-1;
				}
			}
			d[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(d[j]!=-1) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
}
