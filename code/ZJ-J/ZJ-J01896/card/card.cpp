#include <bits/stdc++.h>
using namespace std;
int n,a[500005],m,t,b[500005],nxt[300005];
int ans[300005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		nxt[a[i]]=max(nxt[a[i]],i);
	}
	for(int i=1;i<=n;++i){
		t=0;
		int j=i;
		while(j<=n){
			if(nxt[a[j]]!=j) j=nxt[a[j]];
			b[++t]=a[j];
			++j;
		}
		for(int j=1;j<=t;++j){
			++ans[b[j]];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}