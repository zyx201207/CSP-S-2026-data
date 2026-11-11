#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],s[35],tol;
vector<int> w[35];
map<int,int> mp;
void cheak(int x)
{
	int u=x,cnt=0;
	while(u)
	{
		cnt++;
		if(u%2==1)
		w[cnt].push_back(x);
		u/=2;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cheak(a[i]);
	}
	int f=0,tj=0;
	for(int i=32;i>=1;i--)
	{
		if(w[i].size()<m) continue;
		if(!f)
		{
			tj=1;
			s[i]=1,f=1;
			for(int j=0;j<w[i].size();j++)
				mp[w[i][j]]=tj;
		}
		else
		{
			int cnt=0;
			for(int j=0;j<w[i].size();j++)
			if(mp[w[i][j]]==tj) cnt++;
			if(cnt>=m) 
			{
				s[i]=1;
				tj++;
				for(int j=0;j<w[i].size();j++)
				if(mp[w[i][j]]==tj-1) mp[w[i][j]]=tj;
			}
		}
	}
	for(int i=1;i<=32;i++)
	if(s[i]) tol+=(1ll<<(i-1));
	cout<<tol;
}