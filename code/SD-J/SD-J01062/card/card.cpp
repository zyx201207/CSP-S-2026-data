#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[500005],ans[500005];
bool vis[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=m; i++) {
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
