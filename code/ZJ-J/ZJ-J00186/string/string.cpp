#include <bits/stdc++.h>
using namespace std;
struct ans{
	long long x;
	char y;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
	}
	long long l = 1,r = n,la = 1,ra = 1;
	long long sum = 0;
	while(l < r){
		int rr = min(a[l].x - la + 1,a[r].x - ra + 1);
			if(a[l].y != a[r].y ){
				sum += rr;
			}
			la += rr;
			ra += rr;
			if(la > a[l].x){
				la = 1;
				l ++;
			}
			if(ra > a[r].x ){
				ra = 1;
				r --;
			}
	}
	cout << sum;
	return 0;
}
