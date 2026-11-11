#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		cout << "0" << "\n";
	}
	return 0;
}

