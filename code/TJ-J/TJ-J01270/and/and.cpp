#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m ,ans = 0;
	cin >> n >> m;
	for(int  i = 0;i < n; i++){
		cin >> a[i];
	}
	sort(a[0],a[n]+1,cmp);
	for(int i = 0;i < m; i++){
		b[i] = a[i];
	}
	 for(int i = 0;i < m; i++){
		ans = b[i]&&b[i+1];
	}
	cout << ans;
	return 0;
}
