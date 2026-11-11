#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int End[M];
int nxt[M];
ll ans[M];
int du[M];
void bfs(int m){
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(du[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int y=nxt[x];
		ans[y]+=ans[x];
		du[y]--;
		if(du[y]==0) q.push(y);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		End[a[i]]=i;
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(End[i]!=n){
			nxt[i]=a[End[i]+1];
			du[a[End[i]+1]]++;
		}
	}
	bfs(m);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
