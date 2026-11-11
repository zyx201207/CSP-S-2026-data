#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (n>5000)
	{
		for (int i=0;i<m;i++)
			cout<<n<<' ';
		return 0;
	}
	vector<int> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	vector<int> lst(m+1),ans(m+1,0);
	for (int i=0;i<n;i++)
	{
		fill(lst.begin(),lst.end(),-1);
		for (int j=i;j<n;j++)
		{
			if (lst[a[j]]!=-1)
				for (int k=lst[a[j]];k<j;k++)
					lst[a[k]]=-1;
			lst[a[j]]=j;
		}
		for (int j=1;j<=m;j++)
			ans[j]+=lst[j]!=-1;
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
