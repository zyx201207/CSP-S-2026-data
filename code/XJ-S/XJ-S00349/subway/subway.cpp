#include<bits/stdc++.h>
using namespace std;
int c;//测试点编号 
int n;//地铁线路数 
int m;//地铁战数 
int d;//每个地铁站最多被几条线路经过
int q;//出行计划数 
int w[500005],vis[500005],tong[500005],oppo[500005],fps=0;
vector<int> a[500005],t[500005],tu[500005],ti;
int dijstela(int bgi,int end)
{
	priority_queue<int>ty;
	queue<int>lo;
	memset(vis,0,sizeof(vis));
	int head,tail,ui=0;
	lo.push(bgi);
	vis[bgi]=1;
	while(!lo.empty())
	{
		int skr;
		skr=lo.front();
		lo.pop();
		for(int i=0;i<(int)a[skr].size();i++)
		{
			if(vis[a[skr][i]]==0)
			{
				vis[a[skr][i]]=1;
				lo.push(bgi);
				for(int opp=1;opp<=fps;i++)
				{
					if(a[skr][i]==oppo[i])
					ui=ui+t[skr][i]+t[i][i];
				}
				ui+=t[skr][i];
				if(a[skr][i]==end)
				return ui;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int mm,jj,kk,b[500005],p[500005],bgi,end;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>kk;
		for(int j=1;j<=kk;j++)
		{
			cin>>mm>>jj;
			a[i].push_back(mm);
			tong[mm]++;
			t[i].push_back(jj);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(tong[i]!=1)
		oppo[++fps]=i;
	}
	for(int oo=1;oo<=n;oo++)
	{
		for(int pp=0;pp<(int)a[oo].size()-1;pp++)
		{
			tu[a[oo][pp]].push_back(a[oo][pp+1]);
			tu[a[oo][pp+1]].push_back(a[oo][pp]);
		}
	}
	while(q--)
	{
		cin>>bgi>>end;
		cout<<dijstela(bgi,end)<<endl;
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int pp=0;pp<(int)tu[i].size();pp++)
		cout<<tu[i][pp]<<" ";
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int pp=0;pp<(int)a[i].size();pp++)
		cout<<a[i][pp]<<" ";
		cout<<endl;
	}*/
	return 0;
}
