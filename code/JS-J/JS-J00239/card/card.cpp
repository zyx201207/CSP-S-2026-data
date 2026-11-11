#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5010],vh[3010],dp[3010];
void dfs(int t){
	queue<int>q;
	memset(vh,0,sizeof(vh));
	for(int i=t;i<=n;i++){
		if(vh[a[i]]!=0){
			while(1){
				int p=q.front();
				if(p==a[i]){
					break;
				}else{
					vh[p]--;
				}
				q.pop();
			}
		}else{
			q.push(a[i]);
			vh[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]+=vh[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(dp[i]!=0) cout << dp[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
