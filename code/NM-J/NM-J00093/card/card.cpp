#include<bits/stdc++.h>
using namespace std;
const int N = 500010,M = 300010;
int stk[M],t,n,m,arr[N],cnt[M],vis[M];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 0;i<n;i++)cin>>arr[i];
	for (int i = 0;i<n;i++) {
		t = -1;
		memset(vis,-1,sizeof vis);
		for (int j = i;j<n;j++) {
			if (vis[arr[j]]==-1)stk[++t] = arr[j],vis[arr[j]] = t;
			else {
				for (int k = vis[arr[j]]+1;k<=t;k++)vis[stk[k]] = -1;
				t = vis[arr[j]];
			}
		}
		for (int i = 0;i<=t;i++)cnt[stk[i]]++;
	}
	for (int i = 1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
