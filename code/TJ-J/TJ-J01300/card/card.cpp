#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
bool vis[300005];
int table[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];	
	}
	for(int i = 1;i<=n;i++){
		int p = i;
		for(int j = i;j<=n;j++){
			if(vis[a[j]]){
				p--;
				while(table[p]!=a[j]){
					vis[table[p]]=false;
					p--;
				}
			}
			vis[a[j]]=true;
			table[p]=a[j];
			p++;
		}
		for(int j = i;j<p;j++){
			ans[table[j]]++;
		}
		memset(vis,false,sizeof vis);
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
