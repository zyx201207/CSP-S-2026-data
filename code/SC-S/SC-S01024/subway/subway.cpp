#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=5e2+10;
int readi()
{
	int x=0,f=1;
 	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
long long read()
{
	long long x=0,f=1;
 	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3ll)+(x<<1ll)+c-'0';c=getchar();}
	return x*f;
}
int c,n,m,d,q;
long long w[N];
long long map1[M][M];
struct node
{
	int id;
	long long w;
	node(int id=-1,long long w=0):id(id),w(w){}
};
vector<node> pos[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(map1,0x3f,sizeof(map1));
	c=readi(),n=readi(),m=readi(),d=readi(),q=readi();
	for(int i=1;i<=n;i++) map1[i][i]=0;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k;
		k=readi();
		//cout<<k<<endl;
		for(int j=1;j<=k;j++) 
		{
			int id;
			long long w;
			id=readi(),w=read();
			pos[id].push_back(node(i,w));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int len=pos[i].size();
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++)
			{
				map1[pos[i][j].id][pos[i][k].id]=min(map1[pos[i][j].id][pos[i][k].id],pos[i][j].w+pos[i][k].w);
				map1[pos[i][k].id][pos[i][j].id]=map1[pos[i][j].id][pos[i][k].id];
			}
	}	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j || map1[i][k]==inf || map1[k][j]==inf) continue;
				map1[i][j]=min(map1[i][j],map1[i][k]+map1[k][j]);
			}
	while(q--)
	{
		int l,r;
		l=readi(),r=readi();
		long long minn=inf;
		int len1=(int)pos[l].size(),len2=(int)pos[r].size();
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++)
			minn=min(minn,map1[pos[l][i].id][pos[r][j].id]+pos[l][i].w+pos[r][j].w);
		printf("%lld\n",minn+w[l]+w[r]);
	}
	return 0;
}
/*
 1 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
1 2
*/