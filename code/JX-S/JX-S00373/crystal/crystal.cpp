#include<bits/stdc++.h>
using namespace std;
int n;
long long m, c, x;
long long a[500010];
bool q, b;
int mm(long long qwq){
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        if(qwq >= i){
            ans++;
            qwq -= i;
        }
    }
    return ans;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n == 1){
        cout << 1 << endl;
        return 0;
	}
	q = 1;
	b = 1;
	c = 1;
	for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] == 1) q & bool(a[i] == i);
	}
	sort(a + 1, a + n + 1);
	x = a[2] - a[1];
	for(int i = 2; i <= n; ++i){
        if(a[i] - a[i - 1] != x) b = 0;
	}
	if(q | b){
        m /= x;
        cout << mm(m);
	}
	return 0;
}
