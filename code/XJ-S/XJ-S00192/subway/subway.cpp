#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c;//无
int n;//路线数量
int m;//站点数量
int d;
int q;//询问数
int w[20100];
int k[510];
int a[510][20100];
int t[510][20100];
int r[20100][2];
int xxx[20100][20100];

void djstl(int,int);
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	for(int i = 1;i<=n;i++)
	{
		cin>>k[i];
		for(int j = 1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int i = 1;i<=q;i++)
	{
		cin>>r[i][0]>>r[i][1];
	}
	
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			xxx[i][j] = INT_MAX;
			if(i==j) xxx[i][j] = 0;
		}
	}
	
	
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<k[i];j++)
		{
			for(int kk = j;kk<=k[i];kk++)
			{
				xxx[a[i][j]][a[i][kk]] = t[i][j]+t[i][kk];
				xxx[a[i][kk]][a[i][j]] = t[i][j]+t[i][kk];
			}
		}
	}
	
	
//	for(int i = 1;i<=m;i++)
//	{
//		for(int j = 1;j<=m;j++)
//		{
//			cout<<xxx[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	for(int i = 1;i<=q;i++)
	{
		if(xxx[r[i][0]][r[i][1]]==INT_MAX) djstl(r[i][0],r[i][1]);
		
//		for(int kk = 1;kk<=m;kk++)
//		{
//			for(int j = 1;j<=m;j++)
//			{
//				cout<<setw(11)<<xxx[kk][j];
//			}
//			cout<<endl<<endl;
//		}
		
		cout<<xxx[r[i][0]][r[i][1]]+w[r[i][0]]+w[r[i][1]]<<endl;
	}
	
	return 0;
}
void djstl(int x,int y)
{
	bool f2[20100] = {0};
	bool f[20100] = {0};
	int s[20100];
	f[x] = true;
	for(int i = 1;i<=m;i++)
	{
		s[i] = INT_MAX;
	}
	s[x] = 0;
	int xx = x;
	while(true)
	{
		bool fffff = true;
		for(int i = 1;i<=m;i++)
		{
			if(f2[i]==false)
			{
				fffff = false;
				break;
			}
		}
		if(fffff==true) break;
		for(int i = 1;i<=m;i++)
		{
			if(f[i]==true&&f2[i]==false)
			{
				x = i;
				break;
			}
		}
		
		for(int i = 1;i<=m;i++)
		{
			if(xxx[x][i]!=INT_MAX&&x!=i)
			{
				f[i] = true;
				s[i] = min(xxx[x][i]+s[x],s[i]);
			}
		}
		f2[x] = true;
		
	}
	for(int i = 1;i<=m;i++)
	{
		xxx[xx][i] = s[i];
	}
	
	return;
}
