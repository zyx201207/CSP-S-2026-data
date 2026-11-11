#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
long long n,m,ans=N,A[600000];
int C[510][600000];
bool B[600000];
struct node{
	long long sta,ti,way;
};
vector <node> V1[510],V2[600000];
vector <int> V3[600000];
void dfs(long long x,long long y,long long time,long long wayy)
{
	long long q,w,e,i,j;
	if(x==y)
	{
		time+=C[wayy][y];
		ans=min(ans,time);
		return;
	}
	if(time>=ans) return;
	for(i=0;i<V2[x].size();i++)
	{
		if(B[V2[x][i].sta]!=1)
		{
			if(V2[x][i].way!=wayy)
			{
				B[V2[x][i].sta]=1;
				dfs(V2[x][i].sta,y,time+C[wayy][x]+C[V2[x][i].way][x],V2[x][i].way);
				B[V2[x][i].sta]=0;
			}
			else
			{
				B[V2[x][i].sta]=1;
				dfs(V2[x][i].sta,y,time,wayy);
				B[V2[x][i].sta]=0;				
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long q,m,d,c,i,j,x,y;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>A[i];
	}
	for(i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(j=1;j<=k;j++)
		{
			node no;
			cin>>no.sta>>no.ti;
			no.way=i;
			V1[i].push_back(no);
			C[i][no.sta]=no.ti;
			V3[no.sta].push_back(i);
		}
		for(j=0;j<k-1;j++)
		{
			x=V1[i][j].sta;
			y=V1[i][j+1].sta;
			node no;
			no.way=i;
			no.sta=y;
			no.ti=V1[i][j+1].ti;
			V2[x].push_back(no);
			no.sta=x;
			no.ti=V1[i][j].ti;
			V2[y].push_back(no);
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		for(j=0;j<V3[x].size();j++)
		{
			B[x]=1;
			dfs(x,y,C[V3[x][j]][x],V3[x][j]);
		}
		cout<<ans+A[x]+A[y]<<endl;
		ans=N;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
