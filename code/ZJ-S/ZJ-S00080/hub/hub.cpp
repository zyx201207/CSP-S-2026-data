#include <bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
vector<int> T[17];

int ppct(int x){
	int cnt=0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}

bool vis[17];

void dfs(int now,int lst,int S){
	vis[now]=true;
	for(auto e:T[now]){
		if((S>>(e-1)&1)&&e!=lst){
			dfs(e,now,S);
		}
	}
}

int dep[17];
int dad[17][10];
void lfs(int now,int lst){
	dep[now]=dep[lst]+1;
	dad[now][0]=lst;
	for(auto e:T[now]){
		if(e!=lst){
			lfs(e,now);
		}
	}
}
void ycl(){
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j<=n;j++){
			dad[j][i]=dad[dad[j][i-1]][i-1];
		}
	}
}
int query(int x,int y){
//	cout<<"DEBUG:　"<<x<<' '<<y<<'\n';cout.flush();
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	while(dep[x]>dep[y]){
		x=dad[x][__lg(dep[x]-dep[y])];
//		cout<<"DEBUG: "<<x<<'\n';cout.flush();
	}
//	cout<<"DEBUG: "<<x<<' '<<y<<'\n';cout.flush();
	if(x==y) return x;
	for(int i=__lg(dep[x]);i>=0;i--){
		if(dad[x][i]!=dad[y][i]){
			x=dad[x][i];
			y=dad[y][i];
		}
	}
	return dad[x][0];
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=10;i++) T[i].clear();
		memset(vis,0,sizeof(vis));
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			T[u].push_back(v);
			T[v].push_back(u);
		}
		if(n>10){
			continue;
		}
		memset(dep,0,sizeof(dep));
		memset(dad,0,sizeof(dad));
		lfs(1,0);
		ycl();
//		cout<<query(3,5)<<'\n';
//		cout<<"------------------\n";
		int ans=0x3f3f3f3f;
		for(int s=0;s<(1<<n);s++){
			if(ppct(s)==k){
				int ssc=0;
				for(int i=1;i<=n;i++){
					if(!vis[i]){
						dfs(i,0,s);
						++ssc;
					}
				}
				if(ssc>2) continue;
				
				int tq=0;
				for(int i=1;i<=n;i++){
					if(s>>(i-1)&1) continue;
					for(int j=0;j<n;j++){
						if(j+1==i) continue;
						if(s>>j&1){
							int tmp=dep[i]+dep[j+1]-2*dep[query(i,j+1)];
							tq=max(tq,tmp);
						}
					}
				}
				ans=min(ans,tq);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}