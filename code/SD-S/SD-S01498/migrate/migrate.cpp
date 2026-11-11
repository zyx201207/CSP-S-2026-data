#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,d,as;
int a[2000010];
void bfs(int u,int v){
	if(a[v]-a[u]<=d) return;
	queue<pii>q;
	q.push({u,0});
	int f=0,cnt=1;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(a[i]-a[x]<=d){
				if(i=v){
					if(f==0) f=y;
					else if(f==y) cnt++;
				}
				else{
					q.push({i,y+1});
				}
			}
		}
	}
	if(cnt==2) as++;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i!=j){
				bfs(i,j);
			}
		}
	}
	cout<<as<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

