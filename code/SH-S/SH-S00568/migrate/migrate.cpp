#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N = 2e6 + 10;
long long a[N];
int nxt[N], prv[N];
bool judge(int x, int y){
	vector<int> pth1, pth2;
	int ptr1 = x, ptr2 = y;
	pth1.push_back(x);
	pth2.push_back(y);
	while(ptr1 != y){
		if(nxt[ptr1] == ptr1 && ptr1 < y) return false;
		ptr1 = nxt[ptr1];
		if(ptr1 > y) ptr1 = y;
		pth1.push_back(ptr1);
	}
	while(ptr2 != x){
		ptr2 = prv[ptr2];
		if(ptr2 < x) ptr2 = x;
		pth2.push_back(ptr2);
	}
	bool flag = 0;
	for(int i = 0; i < pth1.size(); i ++){
		int p = pth1[i];
		int q = pth2[(int)pth1.size() - i - 1];
		if(p != q){
			if(p - q > 1 || flag) return false;
			flag = true;
		}
	}
	
	return flag;
}
void solve(){
	long long n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	int tmp = 1;
	for(int i = 1; i <= n; i ++){
		while(a[tmp] - a[i] <= d && tmp <= n) tmp ++;
		nxt[i] = tmp - 1;
	}
	tmp = n;
	for(int i = n; i >= 1; i --){
		while(a[i] - a[tmp] <= d && tmp >= 1) tmp --;
		prv[i] = tmp + 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			if(judge(i, j)) ans ++;
		}
	}
	cout << ans << endl;
}
int main(){
	io;
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --){
		solve();
	}
}
