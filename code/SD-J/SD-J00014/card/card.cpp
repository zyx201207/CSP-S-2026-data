#include<bits/stdc++.h>
using namespace std;
int x[300005];
int k[500005];
int ans[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		x[k[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		int j=i;
		while(j<=n) {
			ans[k[j]]++;
			if(j!=x[k[j]])
				j=x[k[j]]+1;
			else
				j++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
