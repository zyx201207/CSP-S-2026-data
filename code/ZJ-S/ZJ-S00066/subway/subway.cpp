#include<bits/stdc++.h>
#define int long long
using namespace std;
struct no{
	int x,w;
};
int c,n,m,d,T,i,j,len,lenn,x,t,xch[500010],dis[1010][1010],ans,y,k,fx;
vector<int> a[500010],b[500010];
vector<no> e[1010];
no xchh;
queue<int> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>T;
	for(i=1;i<=n;i++)cin>>xch[i];
	for(i=1;i<=m;i++){
		cin>>len;
		for(j=1;j<=len;j++){
			cin>>x>>t;
			a[x].push_back(i);
			b[x].push_back(t);
		}
	}
	for(i=1;i<=n;i++){
		len=a[i].size();
		for(j=0;j<len;j++)
			for(k=j+1;k<len;k++){
				xchh.x=a[i][k];
				xchh.w=b[i][j]+b[i][k];
				e[a[i][j]].push_back(xchh);
				xchh.x=a[i][j];
				xchh.w=b[i][j]+b[i][k];
				e[a[i][k]].push_back(xchh);
			}
	}
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
			dis[i][j]=1e14;
	for(i=1;i<=m;i++){
		q.push(i);
		dis[i][i]=0;
		while(!q.empty()){
			x=q.front();y=dis[i][x];q.pop();
			len=e[x].size();
			for(j=0;j<len;j++){
				fx=e[x][j].x;
				if(dis[i][fx]>y+e[x][j].w){
					dis[i][fx]=y+e[x][j].w;
					q.push(fx);
				}
			}
		}
	}
//	for(i=1;i<=m;i++){
//		for(j=1;j<=m;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
		
	while(T--){
		cin>>x>>y;ans=1e14;
		len=a[x].size();lenn=a[y].size();
		for(i=0;i<len;i++)
			for(j=0;j<lenn;j++)
				ans=min(ans,xch[x]+xch[y]+b[x][i]+b[y][j]+dis[a[x][i]][a[y][j]]);
		cout<<ans<<'\n';
	}
	return 0;
}
