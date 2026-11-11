#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		c[a[i]]=i;
	}
	sort(c+1,c+1+m);
	for(int i=1;i<=m;i++){
		ans[a[c[i]+1]]+=ans[a[c[i]]];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
