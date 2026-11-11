#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,t,n,d,x[maxn];
struct node{
	int a,b; 
};
bool vis[maxn]; 
int bfs(int u,int v){ 
	memset(vis,0,sizeof(vis));
	queue<int>q;
	bool f=0;
	int l=0;
	q.push(u);
	while(!q.empty()){
		auto a=q.front();
		q.pop();
		if(a==v){
			l++;
			f=1;
			continue;
		}
		if(vis[a])continue;
		if(f&&a!=v)continue;
		vis[a]=1;
		for(int b=a+1;b<=v&&x[b]-x[a]<=d;b++)q.push(b);
	}
	return l;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){
			cout<<0<<'\n';
			continue;
		}
		int cnt=0;
		for(int u=1;u<=n;u++){
			for(int v=u+2;v<=n;v++){
				if(bfs(u,v)==2)cnt++;
//				cout<<u<<' '<<v<<endl;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
//rp++
