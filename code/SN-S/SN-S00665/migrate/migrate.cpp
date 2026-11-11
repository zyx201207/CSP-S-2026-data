#include<bits/stdc++.h>
using namespace std;
#define lint long long
struct node{
	lint mi;
	lint z;
};
lint a[200005],c,t,n,m;
node dp[200005];
void dfs(lint x,lint y){
//	cout<<x<<" "<<dp[x].z<<" "<<dp[x].mi<<endl;
	for(int i=x+1;i<=n;i++){
		if(a[x]+m<a[i]){
			break; 
		}
		if(dp[i].mi>y+1){
//			cout<<dp[i].z<<" "<<dp[i].mi<<endl;
			dp[i].z=dp[x].z;
			dp[i].mi=y+1;
			dfs(i,y+1);
		}
		else if(dp[i].mi==y+1){
//			cout<<x<<" "<<i<<" "<<dp[i].z<<" "<<dp[i].mi<<endl;
			dp[i].z+=dp[x].z;
			dfs(i,y+1); 
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		lint ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j].z=0;
				dp[j].mi=1e8;
			}
			dp[i].z=1;
			dfs(i,0);
			for(int j=i;j<=n;j++){
				if(dp[j].z==2){
					ans++;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
