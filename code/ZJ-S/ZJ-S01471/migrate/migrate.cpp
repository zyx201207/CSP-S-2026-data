#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
long long g[N];
int cnt[N],mi[N];
struct obj{
	int x,s;
};
int n;
long long d;
void bfs(int u){
	queue<obj> q;
	q.push({u,0});
	while(q.size()){
		obj t=q.front();
		q.pop();
		for(int i=t.x+1;i<=n;i++){
			if(g[i]-g[t.x]>d) break;
			int ns=t.s+1;
			if(!cnt[i]){
				mi[i]=ns;
				cnt[i]++;
			}else if(ns==mi[i]) cnt[i]++;
			else continue;
			q.push({i,ns});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>g[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(mi,0,sizeof mi);
			memset(cnt,0,sizeof cnt);
			bfs(i);
			for(int j=1;j<=n;j++) ans+=(cnt[j]==2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
