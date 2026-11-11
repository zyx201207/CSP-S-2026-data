#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long cnt[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i!=1 && a[i]<a[i-1]) flag=0;
	}
	if (flag)
	{
		long long sum=1;
		for (int i=2;i<=n;i++)
		{
			if (a[i]!=a[i-1])
			{
				cout<<sum<<" ";
			}
			sum++;
		}
		cout<<sum;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		vector<int> v;
		for (int j=i;j<=n;j++)
		{
			bool flag=0;
			vector<int> nv;
			for (int k=0;k<v.size();k++)
			{
				if (v[k]==a[j]) break;
				nv.push_back(v[k]);
			}
			nv.push_back(a[j]);
			v=nv;
		}
		for (int i=0;i<(int)v.size();i++) cnt[v[i]]++;
	}
	for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
