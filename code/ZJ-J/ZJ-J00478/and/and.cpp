#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,LOGN=32;
int n,m,a[N];
bool vis[N];
void solve(){
	memset(vis,0,sizeof vis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=LOGN-1;i>=0;i--){
		int cntvis=0;
		for(int k=1;k<=n;k++){
			if(vis[k]){
				continue;
			}
			if((a[k]>>i)&1){
				++cntvis;
			}
		}
		if(cntvis>=m){
			ans|=(1<<i);
			for(int k=1;k<=n;k++){
				if(!((a[k]>>i)&1)){
					vis[k]=1;
				}
			}
		}
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
