#include<bits/stdc++.h>
using namespace std;
int n,m,d,c,q1,g,y,fx,x;
long long cnt;
int b[21][502];
int t1[502];
int t2[500000][502];
int s[500000];
int a[500000];
long long minn=10000000;
void dfs(int nx)
{
	if(nx==fx-1)
	{
		cnt+=t1[fx-1];
		minn=min(minn,cnt);
		return;
	}
	for(int i=0;i<m;i++)
	{
		if(b[i][nx]==1)
		{
			cnt+=t2[i][nx];
			for(int j=nx;j<s[i];j++)
			{
				if(b[i][j]==1)
				{
					b[i][j]=0;
					dfs(j);
					b[i][j]=1;
					
				}
			}
			cnt+=t2[i][nx];
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q1;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		t1[i]=x;
	}
	for(int i=0;i<m;i++)
	{
		cin>>g;
		s[i]=g;
		for(int j=0;j<g;j++)
		{
			cin>>x>>y;
			b[i][x-1]=1;
			t2[i][x-1]=y;	
		}	
	}
	int q=q1;
	while(q>0)
	{
		int sx;
		cin>>sx>>fx;
		cnt=t1[sx-1];
		dfs(sx-1);
		a[q]=minn;
		q--;
		minn=1000000;		
	}
	for(int i=q1;i>0;i--)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}