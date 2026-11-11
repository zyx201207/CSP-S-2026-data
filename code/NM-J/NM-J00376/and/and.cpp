#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freeopen("and.in","r",stdin);
	freeopen("and.out","w",stdout);
	int m,n,maxs=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			a[i]=a[i]&a[j];
			maxs=max(maxs,a[i]);
		}
	}
	cout<<maxs;
}
