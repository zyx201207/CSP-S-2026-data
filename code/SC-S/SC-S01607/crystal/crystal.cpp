#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans = INT_MIN, cnt = 1, p, an[N];
int baba = 0;
void solve(int x){
	if ((an[x] - an[x-1] <= m)&&(an[x] - an[x+1] <= m)&&x-1>=1&&x+1<=n&&an[x] - an[x+1] >=0&&an[x] - an[x-1] >=0){
		m=m-an[x]+an[x+1]; m= m-an[x]+an[x-1];
		cnt+=2; an[x+1]=an[x]; an[x-1]=an[x];
		solve(x+1); solve(x-1);
	}else if (an[x] - an[x+1] <= m &&x+1<=1&&an[x] - an[x+1] >=0) {
			cnt++; m = m-an[x]+an[x+1]; an[x+1]=an[x]; solve(x+1);
		}	
	else if((an[x] - an[x-1] <= m )&&x-1>=1&&an[x] - an[x-1] >=0) {
		cnt++; m=m-an[x]+an[x-1]; an[x-1]=an[x]; solve(x-1); 
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	p = m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++){
		if (a[i] = a[i-1]) baba++;
	}
	if(baba=n-1) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		cnt = 1;
		m = p;
		for (int j = 1; j <= n; j++) {an[j] = a[j];}
		solve(i);  ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
} 
