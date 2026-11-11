#include <bits/stdc++.h>
using namespace std;
#define int long long
int mp[1005][1005];
int a[1005];
int c,t,n,m;
struct node{
	int v,l;
};
int bfs(int f){
	if(a[f]!=0){
		return 0;
	}
	queue<node>q;
	q.push({f,0});
	int vis[5005]={};
	vis[f]=1;
	while(q.size()){
		node k=q.front();
		q.pop();
		if(a[k.v]!=0){
			return k.l;
		}
		for(int i=1;i<=n;i++){
			if(mp[k.v][i]==1&&vis[i]==0){
				q.push({i,k.l+1});
			}
		}
	}
	return 1e9;
}
void bfs1(int f){
	queue<int>q;
	q.push(f);
	while(q.size()){
		int k=q.front();
		a[k]=2;
		q.pop();
		for(int i=1;i<=n;i++){
			if(mp[k][i]==1&&a[i]==1){
			
				
				q.push(i);
			}
		}
	}

	return ;
}
int g(int p,int k){
	if(n-p+1<m-k){
		return 1e9;
	}
	if(k==m){
		int maxn=0;
		int huj=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				huj++;
				
				bfs1(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==2){
				a[i]=1;
			}
		}
		if(huj>2){
			return 1e9;
		}
		for(int i=1;i<=n;i++){
			maxn=max(bfs(i),maxn);
			
			
		}
		if(maxn==1){
			for(int i=1;i<=n;i++){
				if(a[i]!=0){
					
				}
			}
		}
		return maxn;
	}
	int minn=1e9;
	a[p]=1;
	minn=min(g(p+1,k+1),minn);
	a[p]=0;
	minn=min(g(p+1,k),minn);
	return minn;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(mp,1e9,sizeof mp);
		for(int i=1;i<n;i++){
			int f,e;
			cin>>f>>e;
			mp[f][e]=mp[e][f]=1;
			
		}
		cout<<g(1,0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
