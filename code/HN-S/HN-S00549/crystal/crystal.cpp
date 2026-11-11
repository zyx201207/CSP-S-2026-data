#include <bits/stdc++.h>
using namespace std;
int n,ans = 1;
long long m,a[500001],b[500001];
int pan(int x,int m,int n){
	int mid = 1;
	for(int j = 1;j <= n;j++) b[j] = a[j]; 
	for(int j = x;j >= 1;j--){
		while((b[j] != b[x]) && (m > 0)){
			b[j]++;
			m--;
		}
		if(m > 0) mid++;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		ans = max(ans,pan(i,m,n));
	}
	cout << ans;
	return 0;
}
