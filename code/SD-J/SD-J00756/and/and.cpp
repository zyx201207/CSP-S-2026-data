#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[int(2* 1e5)+3];
ll it(int x) {
	

}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n,greater<int>());
	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(m == 2) {
		if(a[1]==a[0]){
			cout << a[1] << endl;
			return 0;
		}
		stack  <int> q1;
		stack  <int> q;
		while(a[0]){
			q.push(a[0]%2);
			a[0] /= 2;
		}
		while(a[1]){
			q.push(a[1]%2);
			a[1] /= 2;
		}
		
		int x[2000],y[2000],cnt[2000];
		int x1 = 0,x2 = 0;
		while(!q.empty()){
			x[x1++] = q.top();
			q.pop();
		}
		while(!q1.empty()){
			y[x2++] = q1.top();
			q1.pop();
		}
		for(int i = 0; i < min(x1,x2);i++) {
			cnt[i] = x[i] ^ y[i];
		}
		ll sum = 0;
		for(int i = 0; i < min(x1,x2);i++) {
			sum += cnt[i] *pow(2,i);
		}
		cout << sum << endl;
		return 0;
		
	}
	
	

	return 0;
}

