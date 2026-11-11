#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			ans=max(ans,a[j]&a[i]);
		}
	}
	cout << ans;
	return 0;
}
