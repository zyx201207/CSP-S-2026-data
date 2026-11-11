#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+3;
const ll inf=1e16+3;
struct Numer{
	int v;
	ll w; 
}stk[maxn][25];
int n,rd,taskid,d,q,top[maxn];
//默认n为点数，rd表示路线数 
ll sv[maxn],dv[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>taskid>>rd>>n>>d>>q;
	for(int i=1;i<=rd;i++){
		for(int j=1;j<=rd;j++)dv[i][j]=inf;
		dv[i][i]=0;
	}
	for(int i=1;i<=n;i++)cin>>sv[i];
	for(int i=1,k,v,w;i<=rd;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			stk[v][++top[v]]={i,w};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=top[i];j++){
			for(int k=j+1;k<=top[i];k++){
				int v1=stk[i][j].v,v2=stk[i][k].v;
				dv[v1][v2]=dv[v2][v1]=min(dv[v1][v2],stk[i][j].w+stk[i][k].w);
			}
		}
	}
	for(int mid=1;mid<=rd;mid++){
		for(int u=1;u<=rd;u++){
			if(u==mid)continue;
			for(int v=1;v<=rd;v++){
				if(u==v||v==mid)continue;
				dv[u][v]=min(dv[u][mid]+dv[mid][v],dv[u][v]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll ans=inf;
		int x,y;cin>>x>>y;
		for(int j=1;j<=top[x];j++){
			for(int k=1;k<=top[y];k++){
				ans=min(ans,stk[x][j].w+stk[y][k].w+dv[stk[x][j].v][stk[y][k].v]);
			}
		}
		cout<<ans+sv[x]+sv[y]<<'\n';
	}
	return 0;
}
