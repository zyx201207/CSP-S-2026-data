#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,v[35];
vector<int> g[1000005];
bool ck(int x){
	int cnt=0;
	int mk[35]={};
	queue<int> q;
	for(int i=1;i<=n;i++){
		if (x&(1<<(i-1))){
			q.push(i);
			mk[i]=++cnt;
			break;
		}
	}
	while(!q.empty()){
		int nw=q.front(); 
		q.pop();
		for(int j=0;j<g[nw].size();j++){
			int to=g[nw][j];
			if (x&(1<<(to-1))&&!mk[to]){
				q.push(to);
				mk[to]=mk[nw];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if (x&(1<<(i-1))&&!mk[i]){
			q.push(i);
			mk[i]=++cnt;
			break;
		}
	}
	while(!q.empty()){
		int nw=q.front(); 
		q.pop();
		for(int j=0;j<g[nw].size();j++){
			int to=g[nw][j];
			if (x&(1<<(to-1))&&!mk[to]){
				q.push(to);
				mk[to]=mk[nw];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if (x&(1<<(i-1))&&!mk[i]){
			return false;
		}
	}
	return true;
}
void f(int x){
	for(int j=0;j<g[x].size();j++){
		if (v[x]+1<v[g[x][j]]){
			v[g[x][j]]=v[x]+1;
			f(g[x][j]);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(g,0,sizeof(g));
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (n<=30){
			int ans=30;
			for(int i=1;i<(1<<n);i++){
				if (__builtin_popcount(i)!=k){
					continue;
				}
				if (!ck(i)) continue;
				for(int j=1;j<=n;j++){
					if (i&(1<<(j-1))) v[j]=0;
					else v[j]=999;
				}
				for(int j=1;j<=n;j++){
					if (i&(1<<(j-1))) f(j); 
				}
				int cnt=0;
				for(int j=1;j<=n;j++) cnt=max(cnt,v[j]);
				//for(int j=1;j<=n;j++) cout<<v[j]<<" ";
				//cout<<endl;
				ans=min(ans,cnt);
			}
			printf("%d\n",ans);
		}else{
			if (k>n/2) printf("1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
