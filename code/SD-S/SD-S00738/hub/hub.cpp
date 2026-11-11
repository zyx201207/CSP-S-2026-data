#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,d[2000010],ans,p[2000010];
vector<int> e[2000010];
void bfs(int x){
	queue<int> q;
	q.push(x);
	d[x]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<e[now].size();i++){
			int y=e[now][i];
			if(d[y]>d[now]+1){
				d[y]=d[now]+1;
				q.push(y);
			}
		}
	}
}
void bfs1(int x){
	queue<int> q;
	q.push(x);
	p[x]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<e[now].size();i++){
			int y=e[now][i];
			if(p[y]==1){
				p[y]=0;
				q.push(y);
			}
		}
	}
}
bool check(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(p[i]==1){
			num++;
			if(num>2)break;
			bfs1(i);
		}
	}
	return num>2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		ans=1e9;
		for(int i=1;i<=n-1;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=0;i<(1<<n);i++){
			int num=0;
			for(int j=0;j<n;j++){
				p[j+1]=0;
				if((i>>j)&1){
					num++;
					p[j+1]=1;
				}
			}
			if(num!=k)continue;
			if(check())continue;
			for(int l=1;l<=n;l++){
				d[l]=1e9;
			}
			for(int j=0;j<n;j++){
				if((i>>j)&1){
					bfs(j+1);
				}
			}
			num=0;
			for(int l=1;l<=n;l++){
				num=max(num,d[l]);
			}
			ans=min(ans,num);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
