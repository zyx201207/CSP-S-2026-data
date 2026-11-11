#include<bits/stdc++.h>
using namespace std;

int a[200005];

bool cmp(int a,int b) {
	return a > b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ans;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	ans = a[1];
	for(int i = 2; i <= n; i ++) {
		if((a[i - 1] & a[i]) != 0) {
			ans = (ans & a[i]);
			m --;
		}else {
			ans = a[i];
		}
		if(m == 1) {
			break;
		}
	}
	
	cout << ans;
	
	return 0;
}
