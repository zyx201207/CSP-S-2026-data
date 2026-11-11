#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1e9;
	for(int i=1;i<=n-m;i++){
		int t=a[i];
		for(int j=1;j<=m;j++){
			t=t&a[i+j];
		}
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
}