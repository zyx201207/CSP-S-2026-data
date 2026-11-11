#include<bits/stdc++.h>
using namespace std;
#define int long long
#define I ios::sync_with_stdio(false);
#define AK cin.tie(0);
#define CSP cout.tie(0);
char chmu[200010];
int mu[200010] , w[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	I AK CSP
	int n , ans = 0;
	cin >> n;
	w[1] = 1;
	for(int i = 1;i <=n;i ++){
		cin>> mu[i] >> chmu[i];
	}
	for(int i = 1;i <= n/2;i ++){
		if(chmu[i] != chmu[n-i+1]){
			ans+=mu[i];
		}
	}
	cout<<ans;
	return 0;
}
