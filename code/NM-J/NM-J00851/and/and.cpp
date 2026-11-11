#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[200010];
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cout << int(15 & 12);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout << a[1];
		return 0;
	}
	int ans = a[1];
	for(int i = 2; i <= m; i++){
		ans = int(ans & a[i]);
	}
	cout << ans;
	return 0;
}
