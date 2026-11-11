#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ans=max(a[i],a[i-1]);
	}
	cout << ans;
	return 0;
}
