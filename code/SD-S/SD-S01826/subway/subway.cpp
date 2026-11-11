#include<iostream>
#include<cstdio>
#include<vector>
#include<random>
using namespace std;
const int MAXN=1e4+5;
const int MAXN2=505;
struct nodeee
{
	int w,tot;
	int t[505];
	vector<int> nxt;
};
nodeee node[500005];
vector<int> su[505];
int n,m,d,q;
int anss=0x3f3f3f3f;
bool vis[500005];
void dff(int x,int y,int ans)
{
	if(x==y)
	{
		anss=min(ans,anss);
		return;
	}
	if(!vis[x])
	{
		for(int i=1;i<=505;i++)
		{
			if(node[x].t[i]!=0)
			{
				ans+=node[x].t[i];
				vector<int> ssu=su[i];
				for(int j:ssu)
				{
					if(j!=x)
					{
						vis[x]=1;
						ans+=node[j].t[i];
						dff(j,y,ans);
						ans-=node[j].t[i];
						vis[x]=0;
					}
				}
				ans-=node[x].t[i];
			}
		}
	}
	else return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>node[i].w;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a,tt;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>tt;
			node[a].t[i]=tt;
			su[i].push_back(a);
			node[a].tot++;
		}
	}
	while(q--)
	{
		anss=0x3f3f3f3f;
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans+=node[x].w;
		ans+=node[y].w;
		dff(x,y,ans);
		cout<<anss<<endl;
	}
	return 0;
}

