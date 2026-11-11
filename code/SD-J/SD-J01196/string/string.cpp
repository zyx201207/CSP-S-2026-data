#include <bits/stdc++.h>
using namespace std;

const int M = 2e5;

struct p{
	char ch;
	long long hv;
};

p a[M + 5], b[M + 5];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].hv >> a[i].ch;
		b[i].hv = a[i].hv;
		b[i].ch = a[i].ch;
	}
	reverse(b + 1, b + n + 1);
	long long R = 0, ans = 0, r = 0;
	long long cnt = 0;
	char zf;
	for(int i = 1;i <= n;i++){
		if(cnt + a[i].hv > R){
			while(r + 1 <= n){
				if(R + b[r + 1].hv < cnt + a[i].hv){
					r++;
					zf = b[r].ch;
					if(zf != a[i].ch) ans += b[r].hv;
					R += b[r].hv; 
				}
				else break;
			}
			if(R < cnt + a[i].hv){
				zf = b[r + 1].ch;
				if(zf != a[i].ch){
					ans += (cnt + a[i].hv - R);
				}
				b[r + 1].hv -= (cnt + a[i].hv - R);
				R = cnt + a[i].hv;
			}
			cnt += a[i].hv;
		}
		else{
			if(zf != a[i].ch) ans += a[i].hv;
			cnt += a[i].hv;
		}
	}
	cout << (ans / 2) << endl;
	return 0;
}
