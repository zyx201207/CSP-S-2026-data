#include <bits/stdc++.h>

using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i=0;i<n;i++){
		cin >> a[i] ;
	}
	if (m==1) cout <<n;
	if (m==2) cout << n-m  << n+m;
	return 0;
}
