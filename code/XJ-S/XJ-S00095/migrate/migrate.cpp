#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,num[1000006],ans=0;
void dfs(int cnt,int xb,int ro){
	if(cnt>n){
		if(ro==2){
			ans++;
		}
		return;
	}
	dfs(cnt+1,xb+1,ro+1);
	dfs(cnt+1,xb+2,ro+1);
	dfs(cnt+1,xb,ro);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
