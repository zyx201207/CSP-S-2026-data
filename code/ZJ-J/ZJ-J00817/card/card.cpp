#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,now,fl,a[500010],f[300010],ans[300010];
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;fl=1;
	for(i=1;i<=n;i++){
		cin>>a[i],f[a[i]]=i;
		if(a[i-1]>a[i])fl=0;
	}
	if(fl){
		for(i=1;i<=m;i++)cout<<f[i]<<" ";
		return 0;
	}
	for(i=1;i<=n;i++){
		now=i;
		while(now<=n){
			ans[a[now]]++;
			now=f[a[now]]+1;
		}
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}