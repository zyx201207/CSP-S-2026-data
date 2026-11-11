#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class tree
{
	private:
		int n;
		vector<vector<int>> v;
		vector<int> xuan,noxuan,vis;
		vector<vector<int>> dis;
		queue<int> qu;
		int ans=1e9;
		void dfs2(int pos)
		{
			for(auto i:v[pos])
			{
				auto it=lower_bound(xuan.begin(),xuan.end(),i);
				if(!vis[i] && it!=xuan.end() && *it==i)
				{
					vis[i]=1;
					dfs2(i);
				}
			}
		}
		bool is_two_liantong()
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				vis[i]=0;
			}
			for(auto i:xuan)
			{
				if(!vis[i])
				{
					vis[i]=1;
					dfs2(i);
					cnt++;
				}
			}
			return cnt<=2;
		}
		void dfs(int pos,int xu)
		{
			if(pos==n+1)
			{
				if(xuan.size()!=xu || !is_two_liantong()) return;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						dis[i][j]=-1;
					}
				}
				for(auto i:noxuan)
				{
					qu.push(i);
					dis[i][i]=0;
					while(!qu.empty())
					{
						int f=qu.front();
						qu.pop();
						auto it=lower_bound(xuan.begin(),xuan.end(),f);
						if(it!=xuan.end() && *it==f) continue;
						for(auto j:v[f])
						{
							if(dis[i][j]==-1)
							{
								dis[i][j]=dis[i][f]+1;
								qu.push(j); 
							} 
						}
					}
				}
				int res=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						res=max(res,dis[i][j]);
					}
				}
				ans=min(ans,res);
			}
			if(xuan.size()>xu) return;
			if(noxuan.size()>n-xu) return;
			xuan.push_back(pos);
			dfs(pos+1,xu);
			xuan.pop_back();
			noxuan.push_back(pos);
			dfs(pos+1,xu);
			noxuan.pop_back();
		}
	public:
		void resize(int z)
		{
			n=z;
			v.resize(n+1);
			vis.resize(n+1);
			dis.resize(n+1,vector<int>(n+1));
			for(int i=1;i<n;i++)
			{
				int a,b;
				cin>>a>>b;
				v[a].push_back(b);
				v[b].push_back(a);
			}
		}
		int query(int num)
		{
			dfs(1,num);
			return ans;
		}
		void clear()
		{
			n=0;
			v.clear();
			dis.clear();
			xuan.clear();
			noxuan.clear();
			vis.clear();
			ans=1e9;
		} 
};
int c,q,u,r;
tree tr;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>q;
	while(q--)
	{
		cin>>u>>r;
		tr.resize(u);
		cout<<tr.query(r)<<'\n';
		tr.clear();
	}
	return 0;
}
