#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct sta{
	int id;
	int walk;
	map<int,int> tl;
}tmp;
struct node{
	int v;
	int w;
};
vector<sta> vc;
vector<pair<int,int> > re; 
long long dis[505][505];
int main()
{
	//freopen("subway1.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	vc.push_back(tmp);
	cin>>c>>n>>m>>d>>q;cout<<'l';
	for(long long i=1,w;i<=m;i++)
	{
		cin>>w;
		tmp.id=i;
		tmp.walk=w;
		vc.push_back(tmp);
	}
	memset(dis,0x3f,sizeof dis);	
	for(long long l=1,stas;l<=n;l++)
	{
		cin>>stas;
		for(long long i=1,id=0,t,last;i<=stas;i++)
		{
			last=id;
			cin>>id>>t;
			vc[id].tl[l]=t;
			dis[last][id]=t;
		}
	}
	for(long long i=1,f,s;i<=q;i++)
	{
		cin>>f>>s;
		re.push_back({f,s});
	}
	for(long long k=1;k<=m;k++)
		for(long long i=1;i<=m;i++)
			for(long long j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(auto t:re) 
	{
		auto f=t.first;auto s=t.second;
		cout<<vc[f].walk+vc[s].walk+dis[f][s]+dis[0][f]+dis[0][s]<<endl;
	}
	return 0;
}