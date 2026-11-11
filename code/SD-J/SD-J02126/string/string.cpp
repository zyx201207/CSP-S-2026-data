#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
typedef long long ll;
struct node{
	ll num;
	char zm;
};
node a[N];
ll n,cnt = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	ll lzb = 0;
	char lzm = ' ';
	for(int i = 1;i <= n;i++){
		ll x;
		char y;
		cin >> x >> y;
		if(lzm == y){
			a[lzb].num += x;
		}
		else{
			a[++lzb].zm = y;
			a[lzb].num = x;
			lzm = y;	
		}
	}
	ll l = 1,r = lzb;
	while(l < r){
		if(a[l].num < 0){
			ll jian = a[l].num;
			l++;
			a[l].num += jian;
		}
		if(a[r].num < 0){
			ll jian = a[r].num;
			r--;
			a[r].num += jian;
		}
		if(a[l].num > a[r].num){
			ll jian = 0;
			jian = a[l].num - a[r].num;
			cnt += a[l].num - a[r].num;
			r--;		
			a[r].num -= jian;
		}
		if(a[l].num < a[r].num){
			ll jian = 0;
			jian = a[r].num - a[l].num;
			cnt += a[r].num - a[l].num;
			l++;		
			a[l].num -= jian;
		}
	}
	cout << cnt;
	return 0;
}

