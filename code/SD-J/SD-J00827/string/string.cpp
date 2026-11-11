#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin >> n;
	int len = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int ans = 0;
	int lblock = 1,rblock = n,lbnow = 1,rbnow = 1,ok = 0;
	while(ok < (len+1)/2){
		if(c[lblock] != c[rblock]){
			if(a[lblock]-lbnow+1 >= a[rblock]-rbnow+1){
				ans += a[rblock]-rbnow+1;
				ok += a[rblock]-rbnow+1;
				lbnow += a[rblock]-rbnow+1;
//				cout << a[rblock]-rbnow+1 << " " << lblock << " " << rblock << " " << lbnow << " " << rbnow << " " << ok << "\n";
				rblock--;rbnow = 1;
//				cout << "1" << lbnow << "\n";
			}else{
				ans += a[lblock]-lbnow+1;
				ok += a[lblock]-lbnow+1;
				rbnow += a[lblock]-lbnow+1;
				lblock++;lbnow = 1;
			}
//			cout << "2" << lbnow << "\n";
		}else{
			if(a[lblock]-lbnow+1 >= a[rblock]-rbnow+1){
				ok += a[rblock]-rbnow+1;
				lbnow += a[rblock]-rbnow+1;
				rblock--;rbnow = 1;
			}else{
				ok += a[lblock]-lbnow+1;
				rbnow += a[lblock]-lbnow+1;
				lblock++;lbnow = 1;
			}
		}
//		cout << "3" << rbnow << " " << rblock << " " << a[rblock]+1 << "\n";
		if(lbnow == a[lblock]+1) lblock++,lbnow = 1;
		if(rbnow == a[rblock]+1) rblock++,rbnow = 1;
//		cout << "4" << lbnow << "\n";
//		cout << lblock << " " << rblock << " " << lbnow << " " << rbnow << " " << ok << "\n";
	}
	cout << ans;
}
