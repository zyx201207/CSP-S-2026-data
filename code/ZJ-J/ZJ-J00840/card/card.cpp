#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],lst[300010],ans[300010],cnt[300010];
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int x=lst[i];
		ans[a[x]]+=cnt[i];
		x++;
		while(x<=n){
			x=lst[a[x]];
			ans[a[x]]+=cnt[i];
			x++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
