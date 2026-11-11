#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],b[1005][3],dian[500005],t[500005],di[500005];
int d[500005]={0};
map<int,int>a[500005];
int vis[1005];
struct node
{
	int v,t;
};
vector<node>e[500005];
queue<int>x;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,qqq,q;
	cin>>c>>n>>m>>qqq>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int v1,t1,v2,t2;
		cin>>k[i]>>v1>>t1>>v2>>t2;
		a[v1][v2]=t1+t2;
		a[v2][v1]=t1+t2;
		if(b[v1][1]!=0)
		{
			b[v1][2]=v2;
		}
		else
		{
			b[v1][1]=v2;
		}
		if(b[v2][1])
		{
			b[v2][2]=v1;
		}
		else
		{
			b[v2][1]=v1;
		}
		dian[v1]++;
		dian[v2]++;
	}
	int p=0;
	for(int i=1;i<=500005;i++)
	{
		if(dian[i]==1)
		{
			p=i;
			while(1)
			{
				x.push(p);
				vis[p]=1;
				if(vis[b[p][1]]==0)
				{					
					p=b[p][1];
				}
				else if(vis[b[p][2]]==0)
				{
					p=b[p][2];
				}
				else
				{
					break;
				}
			}
			break;
		}
		
	}
	
	n=x.size()-1;
	for(int i=1;i<=n;i++)
	{
		t[i]=x.front();
		di[t[i]]=i;
		d[i]=a[t[i]][t[i-1]]+d[i-1];
//		cout<<i<<" "<<t[i]<<" "<<d[i]<<endl;
		x.pop(); 
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+abs(d[di[y]]-d[di[x]])<<endl;
	 } 
	return 0;
}
