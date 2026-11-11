#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num;
bool flag[200010];
vector<bool>a[200010];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		flag[i]=1;
		while(num)
		{
			a[i].push_back(num%2);
			num/=2;
		}
		while(a[i].size()<30) a[i].push_back(0);
	}
	int ans=0,cnt;
	for(int w=29;w>=0;w--)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])continue;
			if(a[i][w])cnt++;
		}
		ans*=2;
		if(cnt<m)continue;
		ans++;
		for(int i=1;i<=n;i++)if(!a[i][w])flag[i]=0;
	}
	cout<<ans;
	return 0;
}
