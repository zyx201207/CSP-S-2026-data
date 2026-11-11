#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,a[200086],ans;
int f[1000],mn;
void dfs(int s,int e,int x,int k){
	if(x==e){
		f[k]++;
		mn=min(mn,k);
	}
	for(int i=x+1;i<=e;i++){
		if(a[i]-a[x]<d)dfs(s,e,i,k+1);
		else return;
	}
}
bool check(int u,int v){
	mn=1e9;
	memset(f,0,sizeof(f));
	dfs(u,v,u,0);
	if(f[mn]==2)return 1;
	else return 0;
}
void run(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j))ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		run();
	}
} 
