#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l[500010];
int len[500];
map<int,int>a;
int x[500010][25],xlen[500010],xflag[500010];
int y[510][1200],ylen[500010],yflag[500010];
int flag[500010];
bool fflag[3][500010];
int p[500010];
int t[3][500010];
int di[3][500010];
int st,ed,ans;
void dfs(int xx,int yy,int ll)
{
	cout<<xx<<"¡¡"<<yy<<" "<<ll<<endl; 
	if(yy==ed)
	{
		ans=min(ans,ll);
		return;
	}
	if(xflag[xx]==false&&xlen[xx]>1)
	{
		for(int i=1;i<=xlen[xx];i++)
		{
			xflag[xx]=true;
			dfs(x[xx][i],yy,ll+a[yy*505+x[xx][i]]);
			xflag[xx]=false;
		}
	}
	if(yflag[yy]==false&&ylen[yy]>1)
	{
		for(int i=1;i<=ylen[yy];i++)
		{
			yflag[yy]=true;
			dfs(xx,y[yy][i],ll+a[y[yy][i]*505+xx]);
			yflag[yy]=false;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>l[i];
	if(n==2)
	{
		int minn=2147483647;
		for(int i=1;i<=2;i++)
		{
			int r;
			cin>>r;
			for(int j=1;j<=r;j++)
			{
				cin>>t[i][j];
				flag[t[i][j]]++;
				fflag[i][t[i][j]]=true;
				int tmp;
				cin>>tmp;
				di[i][t[i][j]]=tmp;
				p[t[i][j]]+=tmp;
				if(flag[t[i][j]]==2)
					minn=min(minn,p[t[i][j]]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int st,ed;
			cin>>st>>ed;
			if(fflag[1][st]==true&&fflag[1][ed]==true)
				cout<<l[st]+l[ed]+di[1][st]+di[1][ed]<<endl;
			else if(fflag[2][st]==true&&fflag[2][ed]==true)
				cout<<l[st]+l[ed]+di[2][st]+di[2][ed]<<endl;
			else if(fflag[1][st]==true&&fflag[2][ed]==true)
				cout<<l[st]+l[ed]+di[1][st]+di[2][ed]+minn<<endl;
			else
				cout<<l[st]+l[ed]+di[2][st]+di[1][ed]+minn<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		for(int j=1;j<=len[i];j++)
		{
			int s1,s2;
			cin>>s1>>s2;
			a[s1*505+i]=s2;
			y[i][++ylen[i]]=s1;
			x[s1][++xlen[s1]]=i;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=ylen[i];j++)
//			cout<<y[i][j]<<" ";
//		cout<<endl;
//	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=xlen[i];j++)
//			cout<<x[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++)
	{
		cin>>st>>ed;
		ans=2147483647;
		for(int j=1;j<=xlen[st];j++)
		{
			dfs(st,xlen[j],a[st*505+xlen[j]]);
		}
		cout<<ans+l[st]+l[ed]<<endl;
	}
	return 0;
}

