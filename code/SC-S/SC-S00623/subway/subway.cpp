#include<bits/stdc++.h>
using namespace std;
const int N=550;
long long w[N],k[N],node[N][N],t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long T,n,m,d,q,aaa,ttt,x,y;
	cin>>T>>n>>m>>d>>q;
	if(T==0)
		T=1;
	while(T--)
	{
		long long tz=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++)
			cin>>w[i];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>aaa>>ttt;
				node[aaa][i]=1;
				t[aaa][i]=ttt;
			}
		}
		for(int r=1;r<=q;r++)
			cin>>x>>y;
		for(int j=1;j<=d;j++)
		{
			if(node[x][j]==1&&node[y][j]==1)
				tz=min(tz,w[x]+t[x][j]+w[y]+t[y][j]);	 
		}
		cout<<tz<<" ";
	}
	return 0;
}