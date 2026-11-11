#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int w[500005];
vector<pair<int,int> > tu[600005];
priority_queue<pair<int,int> > hp;
int dis[600005],fl[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),x=read();
			tu[a].push_back({m+i,x});
			tu[m+i].push_back({a,x});
		}
	}
	if(c<=8){
		while(q--){
			int x=read(),y=read();
			for(int i=1;i<=n+m;i++) dis[i]=1e18;
			dis[x]=0;
			hp.push({0,x});
			while(!hp.empty()){
				int v=-hp.top().first,x=hp.top().second;
				hp.pop();
				if(dis[x]!=v) continue;
				for(auto ed:tu[x]){
					int nwu=ed.first,nww=ed.second;
					if(dis[nwu]>dis[x]+nww){
						dis[nwu]=dis[x]+nww;
						hp.push({-dis[nwu],nwu});
					}
				}
			}
			cout<<dis[y]+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fl[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto ed1:tu[i]){
			for(auto ed2:tu[i]){
				int u=ed1.first,v=ed2.first;
				if(u==v){
					fl[u-m][v-m]=0;
					continue;
				}
				int zh=ed1.second+ed2.second;
				fl[u-m][v-m]=min(fl[u-m][v-m],zh);
				fl[v-m][u-m]=min(fl[v-m][u-m],zh);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int minn=1e18;
		for(auto ed1:tu[x]){
			for(auto ed2:tu[y]){
				int u=ed1.first-m,v=ed2.first-m;
				minn=min(minn,fl[u][v]+ed1.second+ed2.second);
			}
		} 
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
} 

