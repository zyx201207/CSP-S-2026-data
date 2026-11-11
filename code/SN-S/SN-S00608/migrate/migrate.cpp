#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e6+10;

int c,t;
int n;
long long d;
long long x[MAXN];
bool vis[MAXN][4];
int fa[MAXN];
int dis[MAXN];

void init(){
	for(int i=1;i<=n;i++) fa[i]=i,dis[i]=1;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool same(int x,int y){
	return find(x)==find(y);
}

void merge(int x,int y){
	if(same(x,y)){
		return;
	}
	dis[find(x)]+=dis[find(y)];
	fa[find(y)]=find(x);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		memset(x,0,sizeof x);
		memset(vis,0,sizeof vis);
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>1) if(x[i]-x[i-1]<=d){vis[i][1]=1,merge(i,i-1);}
			if(i>2) if(x[i]-x[i-2]<=d){vis[i][2]=1,merge(i,i-2);}
			if(i>3) if(x[i]-x[i-3]<=d){vis[i][3]=1,merge(i,i-3);}
		}
		long long _ans=0;
		long long k=0;
		for(int i=1;i<=n;i++){
			if(vis[i][3]){
				if(k!=0) _ans/=k;
				ans+=_ans;
				k=0;
				_ans=0;
				continue;
			}
			if(vis[i][2] && vis[i-1][2]){
				k++;
				_ans+=dis[find(i)]-3;
			}
		}
		if(k!=0) _ans/=k;
		ans+=_ans;
		k=0;
		_ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
