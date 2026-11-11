#include<bits/stdc++.h>
using namespace std;

int ux;

struct L
{
	vector<int> f;
	vector<int> w;
}hct[500006];

struct K
{
	vector<int> z;
	vector<int> w;
}xl[506];

int c,n,m,d,qe;
long long cr[500006];
long long k;
long long u,v;
int ql,qr;

long long h_ans[506][506];

long long h[500006];
bool tz[500006],tl[506];
int dz,dl;
queue<pair<int,bool>> q;

long long ans;

void why_L(int x,int y)
{
	fill(h+1,h+m+1,LONG_MAX);
	fill(tz+1,tz+m+1,0);
	fill(tl+1,tl+n+1,0);
	q.push({x,1});
	tl[x]=1;
	while(!q.empty())
	{
		dz=q.front().first;
		dl=q.front().second;
		q.pop();
		if(dl==0)
		{
			for(int i=0;i<hct[dz].f.size();i++)
			{
				if(tl[hct[dz].f[i]]==0)
				{
					if(h_ans[x][hct[dz].f[i]]>h[dz]+hct[dz].w[i])
					{
						h_ans[x][hct[dz].f[i]]=h[dz]+hct[dz].w[i];
						h_ans[hct[dz].f[i]][x]=h[dz]+hct[dz].w[i];
						tl[hct[dz].f[i]]=1;
						q.push({hct[dz].f[i],1});
					}				
				}

			}
		}
		else
		{
			for(int i=0;i<xl[dz].z.size();i++)
			{
				if(tz[xl[dz].z[i]]==0)
				{
					if(h[xl[dz].z[i]]>h_ans[x][dz]+xl[dz].w[i])
					{
						h[xl[dz].z[i]]=h_ans[x][dz]+xl[dz].w[i];
						tz[xl[dz].z[i]]=1;
						q.push({xl[dz].z[i],0});
					}				
				}

			}
		}
	}
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ux=scanf("%d%d%d%d%d",&c,&n,&m,&d,&qe);
	if(ux!=5) return 1;
	for(int i=1;i<=m;i++)
	{
		ux=scanf("%lld",&cr[i]);
		if(ux!=1) return 2;
	}
	for(int i=1;i<=n;i++)
	{
		ux=scanf("%lld",&k);
		if(ux!=1) return 3;
		for(int j=1;j<=k;j++)
		{
			ux=scanf("%d%d",&u,&v);
			if(ux!=2) return 4;
			xl[i].z.push_back(u);
			xl[i].w.push_back(v);
			hct[u].f.push_back(i);
			hct[u].w.push_back(v);
		}
	}
	while(qe--)
	{
		ux=scanf("%d%d",&ql,&qr);
		ans=cr[ql]+cr[qr];
		if(ux!=2) return 5;
		for(int i=0;i<hct[ql].f.size();i++)
		{
			for(int j=0;j<hct[qr].f.size();j++)
			{
				if(hct[ql].f[i]==hct[qr].f[j])
				{
					ans=max(ans,(long long)(hct[ql].w[i]+hct[qr].w[j]));
				}
				else 
				{
					if(h_ans[hct[ql].f[i]][hct[qr].f[j]]==0)
					{
						why_L(hct[ql].f[i],hct[qr].f[j]);
					}
					ans=max(ans,(long long)(hct[ql].w[i]+hct[qr].w[j]+h_ans[hct[ql].f[i]][hct[qr].f[j]]));
				}
			}
		}
		printf("%lld\n\n",ans);
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
