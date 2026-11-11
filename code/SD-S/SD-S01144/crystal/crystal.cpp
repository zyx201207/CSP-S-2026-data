#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5 + 3;
ll a[N];
int n;
ull m;

bool check1(int x, int num){
	ull sum = 0;
	int cnt = 1;
	for(int i = x - 1;i >= 1;i--){
		if(sum + a[x] - a[i] > m) break;
		sum += a[x] - a[i], cnt++;
	}
	
//	cout <<"x: "<<x<<" cnt: "<<cnt<<'\n';
	
	return cnt >= num;
}

bool check(int x) {
//	cout <<"num: "<<x<<'\n';
	
	int l = x, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if(check1(mid, x)) l = mid;
		else r = mid - 1;
	}
	
	return check1(l, x);
}

int main(){
	IOS;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >>n>>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	sort(a + 1, a + n + 1);
	
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout <<l<<'\n';
}
