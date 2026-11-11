#include<bits/stdc++.h>
using namespace std;
int a[505][100005];
bool b[100005];
int w[100005];
int n,m,c;
long long minn=9999999,cnt=0;
void dfs(int p,int o)
{
	if(p==o)
	{
		cnt+=w[p];
		if(cnt<=minn)
		{
			minn=cnt;
			cnt-=w[p];
			return;
		}
		cnt-=w[p];
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i][p]!=0)&&(cnt+a[i][p]<=minn))
		{
			cnt+=a[i][p];
			for(int j=1;j<=m;j++)
			{
				if((a[i][j]!=0)&&(b[j]!=1)&&(cnt+a[i][j]<=minn))
				{
					b[j]=1;
					cnt+=a[i][j];
					dfs(j,o);
					b[j]=0;
					cnt-=a[i][j];
				}
			}
			cnt-=a[i][p];
		}
		
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int h;
		cin>>h;
		for(int j=1;j<=h;j++)
		{
			int g;
			cin>>g;
			cin>>a[i][g];
		}
	}
	for(int y=1;y<=q;y++)
	{
		int g,h;
		cin>>g>>h;
		b[g]=1;
		cnt+=w[g];
		dfs(g,h);
		cout<<minn<<endl;
		b[g]=0;
		cnt=0;
		minn=9999999;
	}
	return 0;
	//DFS又超时了，TML我恨你！！！！
	//下辈子再也不写DFS了(能剪枝我也不写)！！！！ 
}

