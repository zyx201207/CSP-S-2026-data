#include <bits/stdc++.h>
using namespace std;
long long a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxx=max(maxx,a[i]);
	}
	cout << maxx;
	return 0;
}
