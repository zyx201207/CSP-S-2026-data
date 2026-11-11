#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000001];
int minroad(int u,int v){
	int now=0;
	while(u<v){
		for(int i=v;i>u;i++){
			if(x[i]-x[u]<=d){
				u=i;
				now++;
			}
		}
	}
	return now;
}
int liang,ms;
void dfs(int ci,int u,int v){
	if(u>=v){
		if(ci==ms){
			liang++;
		}
		return ;
	}
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d){
			dfs(ci+1,i,v);
		}
	}
	return ;
}
bool check(int u,int v){
	ms=minroad(u,v);
	liang=0;
	dfs(0,u,v);
	if(liang==2){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
