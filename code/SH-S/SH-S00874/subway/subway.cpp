#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
int m,n,d,q,k[505],w[500050],ttt[500050][505];
//struct stn
//{
//    int u,t,x;	
//};
struct sie
{
	int v,x;
};
struct szz
{
	int u,t;
};
int c;
vector<int> s[500050];
vector<szz> x[500050];
int mn=INT_MAX;
//bool ccmc(stn a,stn b)
//{
//	if(a.u!=b.u)return a.u<b.u;
//	else if(a.t!=b.t)return a.t<b.t;
//	else return a.x<b.x;
//}
bool v[500050];
int zhl;
void fd(int xx,int yy,int nt,int lx)
{
//	printf("xx=%d, yy=%d, nt=%d, lx=%d\n",xx,yy,nt,lx);
	if(xx==yy)mn=min(mn,nt);
	if(nt>mn)return;
	for(int xxx:s[xx])
	{
//		printf("位于%d，选择%d号线\n",xx,xxx) ;
		for(szz vvv:x[xxx])
		{
			if(!v[vvv.u])
			{
				v[vvv.u]=1;
//				printf("位于%d，在%d号线，下一站%d\n",xx,xxx,vvv.u) ;
//				cout << ttt[xx][xxx] << " " << ttt[vvv.u][xxx] << endl;
				if(xxx!=lx)zhl=xxx,fd(vvv.u,yy,nt+ttt[xx][lx]+ttt[xx][xxx],xxx);
				else zhl=xxx,fd(vvv.u,yy,nt,xxx);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++)
	{
		cin >> w[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin >> k[i];
		for(int j=1; j<=k[i]; j++)
		{
			int unn,tnn;cin >> unn >> tnn;
			s[unn].push_back(i);
			x[i].push_back({unn,tnn});
			ttt[unn][i]=tnn;
		}
	}
	while(q--)
	{
		int xx,yy;cin >> xx >> yy;
		memset(v,0,sizeof(v));
		mn=INT_MAX;
		v[xx]=1;
		for(int xxx:s[xx])
		{
			fd(xx,yy,ttt[xx][xxx],xxx);
		}
//		cout << zhl << endl <<  ttt[yy][zhl] << endl;
		cout << mn+w[xx]+w[yy]+ttt[yy][zhl] << endl;
	}
} 
