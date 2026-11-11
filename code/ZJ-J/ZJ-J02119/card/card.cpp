#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009];
int ans[300009],sum[300009],t[500009];
bool vis[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			j=t[a[j]];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
