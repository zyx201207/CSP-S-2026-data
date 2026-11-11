#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,cnt;
ll d,x[2000005];
void dfs(int s,int e,int l){
	if(cnt > 2) return;
	if(s == e){
		cnt++;
		return;
	}
	if(l == 0) return;
	for(int i = s+1;i <= e;i++){
		if(x[i] - x[s] > d) break;
		dfs(i,e,l-1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d %lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
		int ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				int pre = i,len = 0;
				for(int k = i+1;k <= j;k++){
					if(x[k]-x[pre] <= d && x[k+1]-x[pre] > d){
						len++;
						pre = k;
					}
				}
				if(pre < j) len++;
				if(len <= 1) continue;
				cnt = 0;
				dfs(i,j,len);
				if(cnt == 2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}