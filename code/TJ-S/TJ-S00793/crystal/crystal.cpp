#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5; 

int n;
ll m, a[MAXN], diff[MAXN];
ll sum = 0;

int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1;i <=n;i++) diff[i] = abs(a[i] - a[i-1]);
	a[1] = 0;
	for(int i = 1;i <=n;i++){
		sum = sum + diff[i] * (i-1);
		if(sum > m){
			cout << i-1;
			return 0;
		}
	}
	cout << n;
	return 0;
}
 
