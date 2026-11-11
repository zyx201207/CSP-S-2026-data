#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],a[500][500010],t[500][500010],l[500010],minn=10000000000000,sub[500010][500];
void finnd(long long x,long long y,long long ti,long long s)
{
	if(x==y)
	{
		minn=min(minn,ti);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(sub[x][i]==0)break;
		for(int j=1;j<=m;j++)
		{
			if(a[x][j]==0)break;
			if(l[a[x][j]])continue;
			l[a[x][j]]=1;
			if(i!=s){
				ti+=t[x][j]+t[i][j];
			}
			finnd(a[x][j],y,ti,i);
			l[a[x][j]]=0;
			if(i!=s){
				ti-=t[x][j]+t[i][j];
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j+=1)
		{
			cin>>a[i][j]>>t[i][j];
			int p=1;
			while(sub[a[i][j]][p])
			{
				p++;
			}
			sub[a[i][j]][p]=i;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		finnd(x,y,0,0);
	}
	return 0;
 } 
