#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll A[200005];
bool vis[200005][40];
bool cnt[200005][40];
int cnt2;
ll ans;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		int j=0;
		while(A[i]){
			vis[i][j]=(A[i]&1);
			j++;
			A[i]/=2;
		}
	}
	for(int i=1;i<=n;i++){
		cnt[i][31]=1;
	}
	for(int j=30;j>=0;j--){
		cnt2=0;
		for(int i=1;i<=n;i++){
			if(vis[i][j]==1&&cnt[i][j+1]==1){
				cnt2++;
				cnt[i][j]=1;
			}
		}
		if(cnt2>=m){
			ans+=(1<<j);
		}else{
			for(int i=1;i<=n;i++){
				cnt[i][j]=cnt[i][j+1];
			}
		}
	}
	printf("%lld",ans);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}