#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
int c,n,m,d,q,w[M];
struct xx
{
	int v,w;
};
vector<xx> v[M+500];
struct yy
{
	int v,w;
	bool friend operator < (yy ax,yy ay)
	{
		return ax.w>ay.w;
	}
};
priority_queue<yy> pq;

int rd()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0' || c>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	c=rd(); n=rd(); m=rd(); d=rd(); q=rd();
	for(int i=1;i<=m;i++)
	{
		w[i]=rd();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		k=rd();
		for(int j=1;j<=k;j++)
		{
			int vv,ww;
			vv=rd(); ww=rd();
			v[m+i].push_back({vv,ww});
			v[vv].push_back({m+i,ww});
		}
	}
	while(q--)
	{
		int s,t,sum=0;
		s=rd();t=rd();
		while(!pq.empty()) pq.pop();
		
		for(int i=0;i<v[s].size();i++) pq.push({v[s][i].v,v[s][i].w});
		while(!pq.empty())
		{
			yy c=pq.top();
			pq.pop();
			
			//cout<<"Debug "<<c.v<<" "<<c.w<<endl;
			
			if(c.v==t)
			{
				cout<<c.w+w[s]+w[t]<<endl;
				break;
			}
			
			for(int i=0;i<v[c.v].size();i++)
			{
				if(v[c.v][i].v==c.v) continue;
				pq.push({v[c.v][i].v,c.w+v[c.v][i].w});
			}
		}
	}
	
	return 0;
}//RP++
/*
//freopen("subway.in","r",stdin);
//freopen("subway.out","w",stdout);
*/
