#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 5e5+10,M = 3e5+10;
int a[N],ans[M],pai[N],paii[M],len;
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis));
		len = 0;
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				memset(vis,0,sizeof(vis));
				len = paii[a[j]]-1;
				for(int k = len;k >= 1;k--) vis[k] = 1;
			}
			vis[a[j]] = 1;
			pai[++len] = a[j];
			paii[a[j]] = len;	
		}
		for(int i = 1;i <= len;i++) ans[pai[i]]++;
	} 
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
