#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	vector<int>a1;
	map<int,int>mp;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=m; i++) {
		mp.insert({i,0});
	}
	for(int i=0;i<m;i++) {
		cout<<n<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
