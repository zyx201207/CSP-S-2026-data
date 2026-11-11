#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],sum=0,ans=0,mn_st;
void dfs(int now,int ed,int st){
	if(now==ed){
		sum++;
		mn_st=min(mn_st,st);
		return;
	}
	for(int i=now;i>=ed;i--){
		if(a[now]-d>=a[i]) dfs(i,ed,st+1);
		else continue;
	}
	return;
}
void dfs2(int now,int ed,int st){
	if(now==ed){
		if(st!=mn_st) sum--;
		return;
	}
	for(int i=now;i>=ed;i--){
		if(a[now]-d>=a[i]) dfs(i,ed,st+1);
		else continue;
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
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;
				dfs(j,i,0);
				dfs2(j,i,0);
				if(sum==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}