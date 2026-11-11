#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
	int x;
	char c;
}a[222222];
long long cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int xx;
		char cc;
		cin >> xx >> cc;
		a[i].x = xx;
		a[i].c = cc;
	}
	for(int l = 1, r = n; l <= r; ){
		if(a[l].c != a[r].c){
			cnt += min(a[l].x, a[r].x);
			if(a[l].x > a[r].x){
				a[l].x -= a[r].x;
				r--;
			}else if(a[l].x < a[r].x){
				a[r].x -= a[l].x;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].x > a[r].x){
				a[l].x -= a[r].x;
				r--;
			}else if(a[l].x < a[r].x){
				a[r].x -= a[l].x;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout << cnt;
}
