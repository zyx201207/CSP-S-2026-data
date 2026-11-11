#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int c = 1;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; 
	long long m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a, a+n);
	while(m - (a[c]-a[c-1])*c>=0&&c<n){
		m -= (a[c]-a[c-1])*c;
		c++;
	}
	cout<<c;
	return 0;
}
