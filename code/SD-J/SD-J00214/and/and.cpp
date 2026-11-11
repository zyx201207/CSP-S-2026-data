#include <bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int maxx=-1;
int n,m;
int a[N],vis[N];
vector <int>v;
void dfs(int u){
	if(u==m+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt++;
			}
		}
		if(cnt==m){
			int res=v[0];
			for(int i=1;i<v.size();i++){
				res=res&v[i];
			}
			maxx=max(maxx,res);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(a[i]);
		dfs(u+1);
		vis[i]=0;
		v.pop_back(); 
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=n){
		dfs(1);
		cout<<maxx;
	}else{
		sort(a+1,a+1+n,cmp);
		maxx=a[1];
		for(int i=2;i<=m;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}
	
	return 0;
}
