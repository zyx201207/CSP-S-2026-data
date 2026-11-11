#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans[500005],a[500005],s[300005],ud[300005],f,wj[500005];
vector<int> wi[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
		ans[a[i]]++;
		wi[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int len=wi[i].size();
		for(int j=0;j<len-1;j++)
			wj[wi[i][j]]=wi[i][j+1];
	}
	if(!f)
	{
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			cnt+=ans[i];
			cout<<cnt<<" ";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int q=i;
			while(q<=n)
			{
				if(!wj[q]) 
				{
				    ud[a[q]]++;
					q++;
				}
				else
				{
					q=wj[q];
				}
			}
			for(int i=1;i<=m;i++)
			if(ud[i]) s[i]++,ud[i]=0;
		}
		for(int i=1;i<=m;i++)
		cout<<s[i]<<" ";
	}
}