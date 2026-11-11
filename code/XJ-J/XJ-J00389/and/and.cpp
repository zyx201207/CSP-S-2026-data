#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	unsigned long long a[200005];
	int n,m,b=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	unsigned long long ans=a[1];
	for (int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}