#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int nxt[N];
int num[N];
int n,m;
int a[N];
int ans[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	memset(nxt,-1,sizeof(nxt));
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		nxt[num[a[i]]]=i;
		num[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		if(nxt[i]==-1)nxt[i]=i+1;
	}
	for(int i=1; i<=n; i++) {
		int now=i;
		while(now<=n) {
			while(now<=n&&a[now]==a[nxt[now]]) {
				now=nxt[now];
			}
			ans[a[now]]++;
			now=nxt[now];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}//1000000000
