#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],ans[300005],k[500005];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		lst[a[i]]=i;
		k[i]=1;
	}
	for(int i=1; i<=n; i++) {
		ans[a[i]]+=k[i];
		k[lst[a[i]]+1]+=k[i];
	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i];
		if(i!=m)cout<<" "; 
	}
	return 0;
}
