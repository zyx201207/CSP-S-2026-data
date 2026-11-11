
#include<bits/stdc++.h>
using namespace std;
int x[1000005],vis[1000005];
int cur,minn=2e9,c,t,n,d;
void dfs(int op,int b,int sum){
	if(op==b){
		if(minn>sum){
			minn=sum;
			cur=1;
		}else if(minn==sum) cur++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==op) continue;
		if(!vis[i]&&abs(x[op]-x[i])<=d){
			vis[i]=1;
			dfs(i,b,sum+1);
			vis[i]=0;
		} 
	}
}
int solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cur=0,minn=2e9;
			vis[i]=1;
			dfs(i,j,0);
			vis[i]=0;
			if(cur==2) cnt++;
		}
	} 
	return cnt;
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
		cout<<solve()<<endl;
	}	
	return 0;
}