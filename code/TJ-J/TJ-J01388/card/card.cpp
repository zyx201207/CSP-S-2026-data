#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[500005], cnt[300005], vis[500005], st[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		int l = 1;
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 0 || vis[a[j]] > l){
				vis[a[j]] = l;
				
			}
			else {
				l = vis[a[j]];
				
			}
			st[l++] = a[j];
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i < l; i++){
			if(st[i] != 0){
				vis[st[i]] = 1;
			}
		}
		for(int i = 1; i <= m; i++){
			cnt[i] += vis[i];
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

