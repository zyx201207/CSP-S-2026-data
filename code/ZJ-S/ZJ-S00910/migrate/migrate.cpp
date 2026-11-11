#include<bits/stdc++.h>
using namespace std;
int op,T,n,m,ans,i,j,s,a[2001000];
long long mi;
void dfs(int x,int y,int z){
	if(mi<z){
		return ;
	}if(x==y){
		if(mi>z){
			mi=z;
			s=1;
		}else{
			s++;
		}
	}for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=m){
			dfs(i,y,z+1);
		}else{
			break;
		}
	}
}bool pd(int x,int y){
	s=0;mi=1e18;
	dfs(x,y,0);
	if(s==2){
		return 1;
	}else{
		return 0;
	}
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>op>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(pd(i,j)){
					ans++;
				}
			}
		}cout<<ans<<"\n";
	}return 0;
}
