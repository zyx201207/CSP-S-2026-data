#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	for (int i=1;i<=n;i++){
		ans=max(a[i]^a[i+1],a[i+1]^a[i+2]);
	}
	cout<<ans;
	return 0;
}
