#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int st,fi,minn=1e9;
int w[500005];
bool flag[500005];
int a[50005][505];
void dfs(int id,int step,int l)
{
	if(step>=minn)
	{
		return;
	}
	if(id==fi)
	{
		minn=min(minn,step+w[id]+a[id][l]);
		return;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=m;i++)
		{
			if(a[id][j]!=0&&a[i][j]!=0&&flag[i]==false&&l!=j)
			{
				flag[i]=true;
				dfs(i,step+a[id][l]+a[id][j],j);
				flag[i]=false;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i][l]!=0&&a[id][l]!=0&&flag[i]==false)
		{
			flag[i]=true;
			dfs(i,step,l);
			flag[i]=false;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int id,va;
			cin>>id>>va;
			a[id][i]=va;
		}
    }
    while(q--)
    {
    	minn=1e9;
    	memset(flag,false,sizeof(flag));
    	cin>>st>>fi;
    	for(int i=1;i<=n;i++)
    	{
    		if(a[st][i]!=0)
    		dfs(st,w[st]+a[st][i],i);
		}
    	cout<<minn<<endl;
	}
	return 0;
}
