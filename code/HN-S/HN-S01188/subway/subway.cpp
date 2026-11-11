#include<bits/stdc++.h>
using namespace std;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c,n,m,d,q,r;
	cin>>c>>n>>m>>d>>q;
	int a[m],b[n],t[1000];
	for(int i=0;i<m;i++){
		cin>>a[i];
	} 
	cin>>r;
	for(int j=0;j<n;j++){
		for(int i=0;i<r;i++)
			cin>>b[i]>>t[i];
	}

	for(int j=0;j<q;j++){
		cin>>x>>y;
	}
	return 0;
}

