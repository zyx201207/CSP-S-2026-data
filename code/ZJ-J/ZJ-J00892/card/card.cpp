#include<bits/stdc++.h>
using namespace std;
const int slen=5e5+10;
int a[slen],ans[slen];
int que[slen],tail=0;
bool f[slen];
map<int,int> mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	bool tepan=1;
	for(int i=1;i<=n;i++)	
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		tail=0;
		mp.clear();
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1&&mp[a[j]]<tail)
			{
				tail=mp[a[j]]+1;
			}
			if(f[a[j]]==0||mp[a[j]]>=tail)
			{
				que[tail]=a[j];
				mp[a[j]]=tail;
				f[a[j]]=1;
				tail++;
			}
		}
		for(int j=0;j<tail;j++)	ans[que[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
