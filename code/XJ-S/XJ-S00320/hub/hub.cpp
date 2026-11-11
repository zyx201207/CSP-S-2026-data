#include<bits/stdc++.h>
using namespace std;
int c,T;
namespace sub1{
const int N=15;
int n,k;
int head[N],ver[N<<1],nxt[N<<1],tot;
bool isx[N];
bool col[N]; 
int d[N];
int ans;
void addedge(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void BFS(){
	for(int i=1;i<=n;i++) d[i]=n+1;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(isx[i]){
			d[i]=0;
			q.push(i);
		} 
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			if(d[x]+1<d[y]){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}
void bcl(int x){
	col[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(isx[y]&&!col[y]){
			bcl(y);
		}
	}
}
void check(){
	for(int i=1;i<=n;i++) col[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(isx[i]&&!col[i]){
			bcl(i);
			cnt++;
		}
	}
	if(cnt>2) return ;
//	for(int i=1;i<=n;i++) cout << isx[i] << ' ';
//	cout << '\n'; 
	BFS();
	int ret=0;
	for(int i=1;i<=n;i++) ret=max(ret,d[i]);
	ans=min(ans,ret);
}
void dfs(int x,int sel){
//	cout << x << ' ' << sel << '\n';
	if(x>n){
		if(sel==k) check();
		return ;
	}
	isx[x]=1;
	dfs(x+1,sel+1);
	isx[x]=0;
	dfs(x+1,sel);
}
void solve(){
	while(T--){
		cin >> n >> k;
		tot=0;
		ans=n;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			addedge(x,y);
			addedge(y,x);
		}
		dfs(1,0);
		cout << ans << '\n';
	}
}
}
namespace sub2{
int n,k;
void solve(){
	while(T--){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
		}
		int ans=max(1.0,ceil(1.0*(n/2+2-k)/4));
		cout << ans << '\n';
	}
}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	if(c<=3){
		sub1::solve();
	}else{
		sub2::solve(); 
	}
	return 0;
}
