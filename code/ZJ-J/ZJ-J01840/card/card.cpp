#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],nxt[N],cnt[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nxt[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=nxt[i];j<=n;j++){
			j=nxt[a[j]];
			ans[a[j]]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	
	
	return 0;
}
