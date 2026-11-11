#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=2e6+10;
int c,t,n,d,a[N],dp[N];
struct T{
	int x,step;
};
int bfs1(int x,int y){
	queue<T> q;
	q.push({x,0});
	while(!q.empty()){
		int x=q.front().x,step=q.front().step;
		q.pop();
		if(x==y) return step;
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]<=d){
				q.push({i,step+1});
			}
		}
	}
	return 1e18;
}
int bfs2(int x,int y,int minn){
	queue<T> q;
	q.push({x,0});
	int cnt=0;
	while(!q.empty()){
		int x=q.front().x,step=q.front().step;
		q.pop();
		if(x==y){
			if(step==minn) cnt++;
		}
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]<=d&&step<=minn){
				q.push({i,step+1});
			}
		}
	}
	return cnt;
}
int fang(int x,int y){
	int minn=bfs1(x,y);
	return bfs2(x,y,minn);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(fang(i,j)==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
