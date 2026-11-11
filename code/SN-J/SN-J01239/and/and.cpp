#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(a[i]&a[i-1],mx);
	}
	cout<<mx;
	return 0;
}
