#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a[n];
	int nyu[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	} 
	if(m == 1){
		sort(a,a+n,greater<int>());
		cout << a[0];
		return 0;
	}
	if(m == n){
		int ans = 0;
		for(int i=0;i<n;i++){
			ans += ans&a[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j)continue;
			nyu[i] = a[i]&a[j];
		} 
	}
	sort(nyu,nyu+n,greater<int>());
	cout << nyu[0];
	return 0;  
} 
