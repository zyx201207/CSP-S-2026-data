#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
ll d;
int x[100005];
bool vis[100005];
int ans;
void solve() {
	ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n-3;i++){
		if(x[i+3]-x[i+1]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i]>d){
			vis[i]=1;
		}
	}
	for(int i=1;i<=n-4;i++){
		if(x[i+4]-x[i+1]<=d&&x[i+3]-x[i]<=d&&x[i+4]-x[i]>d){
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			for(int j=i;vis[j]==1;j--){
				ans++;
			}
			for(int j=i+3;vis[j]==1&&j<=n;j++){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	return;
}
int main() {
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}