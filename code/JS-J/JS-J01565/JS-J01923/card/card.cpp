#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug printf
#else
int debug(...){return 0;}
#endif
int n,m,a[500005];
int las[300005];
int nxt[500005];
int cnt[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef LOCAL
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[las[a[i]]] = i;
		las[a[i]] = i;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			while(nxt[j]) j=nxt[j];
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
