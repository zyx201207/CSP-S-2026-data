#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
vector<int> zm;
int n,a[500005],m;
int dq;
int flag[500005];
int cnt[500005];
int sum[5];
int b[500005];
bool flag222;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag222=true;
	}
	if(m<=2 and n>=500)
	{
		for(int i=1; i<=n; i++)
		{
			if(a[i]==a[n]) cnt[a[1]]++;
			else cnt[a[1]]++,cnt[a[2]]++;
		}
		for(int i=1; i<=m; i++)
		{
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	if(flag222==false)
	{
		for(int i=1; i<=n; i++)
		{
			if(a[i]!=a[i-1]) cnt[a[i]]+=i;
		}
		for(int i=1; i<=m; i++) cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		zm.clear();
		for(int j=1; j<=n; j++) flag[a[j]]=-1;
		for(int j=i; j<=n; j++)
		{
			if(flag[a[j]]==-1) zm.push_back(a[j]),flag[a[j]]=zm.size();
			else
			{
				for(int k=zm.size(); k>flag[a[j]]; k--)
				{
					flag[zm[zm.size()-1]]=-1;
					zm.pop_back();
				}
				zm.push_back(a[j]),flag[a[j]]=zm.size();
			}
		}
		for(int j=1; j<=m; j++)
		{
			if(flag[j]!=-1) cnt[j]++;
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

