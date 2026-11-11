#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],sum[500005],ans[300005],k[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=(1+sum[i]);
		sum[k[a[i]]+1]+=(1+sum[i]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
