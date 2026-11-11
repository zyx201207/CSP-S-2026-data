#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],ans[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=1;
		ans[m+1]-=1;
	}
	for(int i=1;i<=m;i++){
		ans[i]+=ans[i-1];
		cout<<ans[i]<<" ";
	}
}
