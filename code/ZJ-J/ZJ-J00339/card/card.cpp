//4
#include<bits/stdc++.h>
using namespace std;
//#define int long long
long long n,m,a[510000],vis[310000],sum[310000];
vector<int> num;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			vis[a[j]]++;
			if(vis[a[j]]>1)
			{
				while(num.size() && num.back()!=a[j])
					vis[num.back()]--,num.pop_back();
				num.pop_back();
				vis[a[j]]--;
			}
			num.push_back(a[j]);
		}
		while(num.size())
		{
			sum[num.back()]++;
			num.pop_back();
		}
	}
	cout<<sum[1];
	for(int i=2;i<=m;i++)
		cout<<" "<<sum[i];
	return 0;
}