#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	int a[50010];
	int vis[30010]={0};
	int cnt[30010]={0};// zong jishuqi
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int y=1;y<=n;y++)
	{
		vector< int >v;
		v.clear();
		memset(vis,0,sizeof(vis));
		for(int i=y;i<=n;i++)
		{
			//a[i] fangzhi
			if(vis[a[i]]!=0)
			{
				while(!v.empty()&&v[v.size()-1]!=a[i])
				{
					vis[v[v.size()-1]]=0;
					v.pop_back();
				}
			}
			else
			{
				v.push_back(a[i]);
				vis[a[i]]=v.size()-1;
			}
		}
		for(int i=1;i<=m;i++) if (vis[i]!=0)cnt[i]++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
