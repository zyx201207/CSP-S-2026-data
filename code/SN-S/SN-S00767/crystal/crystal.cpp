#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N],b[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int ok1 = 1,ok2 = 1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i]!=i){
			ok1 = 0;
		}
	}
	if(ok1){
		if(m>=n*(n-1)/2){
			cout << n;
		}else{
			for(int i = 1;i <= n;i ++){
				if((1+i)*i/2>=m){
					cout << i;
					break;
				}
			} 
		}
	}else{
		sort(a+1,a+n+1);
		int d = a[2]-a[1];
		for(int i = n;i >= 1;i --){
			if(a[i]-a[i-1]!=d){
				ok2 = 0;
				break;
			}
		}
		if(ok2){
			if(m>=(a[1]+a[n-1])*(n-1)/2){
				cout << n;
			}else{
				for(int i = 1;i <= n;i ++){
					if((a[1]+a[i])*i/2>=m){
						cout << i;
						break;
					}
				} 
			}
		}else{
			for(int i = 1;i <= n;i ++){
				b[i] = b[i-1]+a[i];
			}
			int ans = -1;
			for(int i = n;i >= 1;i --){
				for(int j = 1;j <= n;j ++){
					if(a[i]*j-(b[i]-b[i-j])>m){
		//				cout << a[i]*i << " " << b[i] << "\n";
						ans = max(ans,j-1);
						break;
					}
				}
			}
			cout << ans;
		}
//		cout << a[315275] << " " << b[315275] <<  " " << a[315275]*315275-b[315275];
	}
	return 0;
}
/*

5 8
-3 -1 2 2 7

*/

