#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000001],n,d,ans=0,way,mi;
void dfs(int now,int pos,int dis){
	if(now==pos){
		if(mi==-1){
			way=1;
			mi=dis;
			return;
		}
		if(mi>dis){
			way=1;
			mi=dis;
		}else if(mi==dis){
			way++;
		}
		return;
	}
	for(int i=now+1;i<=pos;i++){
		if(a[i]-a[now]<=d){
			dfs(i,pos,dis+1);
		}else{
			break;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		if(n>5000){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				way=0;
				mi=-1;
				dfs(i,j,0);
				if(way==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
