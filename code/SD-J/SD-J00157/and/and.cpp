#include<bits/stdc++.h>
using namespace std;
#define I ios::sync_with_stdio(false);
#define AK cin.tie(0);
#define CSP cout.tie(0);
int a[200010] , b[200010];
int main(){
	I AK CSP
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 30;i >= 0;i --){
		int cnt = 0;
		for(int j = 1;j <= n;j ++){
			if(b[j] == 0 && ((a[j]>>i)&1)){
				cnt++;
			}
		}
		if(cnt >= m){
			ans += (1<<i);
			for(int j = 1;j <= n;j ++){
				if(b[j] == 0 && ((a[j]>>i)&1)){
					cnt++;
				}else{
					b[j] = 1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
