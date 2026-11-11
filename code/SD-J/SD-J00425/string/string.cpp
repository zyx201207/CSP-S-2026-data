#include<bits/stdc++.h>
#define pb push_back
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
#define endl '\n'
#define int long long
using namespace std;

const long long MAXN = 1e9 + 1;
int n;
long long len = 0;
char s[MAXN];
int ans1 = 0, ans2 = 0;
int mid;

void solve1(){
	char s1[mid + 15], s2[mid + 15];
	zxh(1, mid - 1, 1, i){
		s1[i] = s[i];
	}
	zxh(1, mid - 1, 1, i){
		s2[i] = s[mid + i];
	}
	zxh(1, mid - 1, 1, i){
		if(s1[i] != s[len - i + 1]) ans1++;
	}
	zxh(1, mid - 1, 1, i){
		if(s2[i] != s[mid - i]) ans2++;
	}
	cout << min(ans1, ans2);
}

void solve2(){
	char s1[mid + 15], s2[mid + 15];
	zxh(1, mid, 1, i){
		s1[i] = s[i];
	}
	zxh(1, mid, 1, i){
		s2[i] = s[mid + i];
	}
	zxh(1, mid, 1, i){
		if(s1[i] != s[len - i + 1]) ans1++;
		if(s2[i] != s[mid - i]) ans2++;
	}
	cout << min(ans1, ans2);
}

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	zxh(1, n, 1, i){
		int x;
		char c;
		cin >> x >> c;
		zxh(1, x, 1, qwq){
			s[len + qwq] = c;
		}
		len += x;
	}
	if(len % 2 == 1){
		mid = (len / 2) + 1;
		solve1();
	} else if(len % 2 == 0){
		mid = len / 2;
		solve2();	
	}
	return 0;
} 

/*
报错3221225725,3221225477是什么玩意，RE吗
应该能拿64分的部分分 
不要爆掉orz 
*/
