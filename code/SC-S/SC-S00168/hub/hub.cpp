#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,dep[N],mx,id,depst[N];
vector<int>g[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	depst[x]=dep[x];
	if(dep[x]>mx){
		mx=dep[x];
		id=x;
	}
	for(auto y:g[x]){
		if(y==fa) continue;
		dfs(y,x);
		depst[x]=depst[y];
	}
}
int dfs2(int x,int fa,int dis,int li,int cod){
	int num=0,f=0;
	if(cod==1||cod==3){
		for(auto y:g[x]){
			if(y==fa) continue;
			if((depst[y]-dep[y]+1>=li&&depst[y]!=mx)||dis>li){
				f=1;
				break;
			}
		}
		if(f){
			num++;
			for(auto y:g[x]){
				if(y==fa) continue;
				num+=dfs2(y,x,0,li,2);
			}
		}
	}else{
		for(auto y:g[x]){
			if(y==fa) continue;
			if(depst[y]-dep[y]+1>li&&depst[y]!=mx){
				num+=depst[y]-dep[y]+1-li;
				f=1;
			}
		}
		if(f){
			num++;
			for(auto y:g[x]){
				if(depst[y]==mx) num+=dfs2(y,x,0,li,2);
			}
		}else{
			for(auto y:g[x]){
				if(y==fa) continue;
				num+=dfs2(y,x,1,li,3);
			}
		}
	}
	return num;
}
bool check(int x){
	int num=dfs2(id,0,1,x,1);
	return num<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) dep[i]=0;
		mx=0;
		dfs(id,0);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<l<<"\n";
	}
}