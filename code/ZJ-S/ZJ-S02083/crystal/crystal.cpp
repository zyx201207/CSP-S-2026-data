#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
long long a[N],m;
int n,ans;
bool flagdc = 1,flagxa = 1;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long cz = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		if((a[i] - a[i-1]) != cz){
			flagdc = 0;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(a[i] < -200 || a[i] > 200){
			flagxa = 0;
			break;
		}
	}
	if(flagdc == 1){
		long long cnt = 0;
		ans = 1;
		for(int i = n-1; i >= 1; i--){
			cnt = cnt + a[n] - a[i];
			if(cnt <= m) ans++;
			else{
				break;
			}
		}
		cout << ans;
		return 0;
	}
	if(flagxa == 1){
		ans = 1;
		for(int i = 2; i <= n; i++){
			int tot = 1;
			long long cnt = 0;
			for(int j = i-1; j >= 1; j--){
				cnt = cnt + a[i] - a[j];
				if(cnt <= m){
					tot++;
				}
				else break;
			}
			while(a[i] == a[i+1]){
				i++;
				tot++;
			}
			if(ans < tot) ans = tot;
		}
		cout << ans;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		int tot = 1;
		long long cnt = 0;
		for(int j = i-1; j >= 1; j--){
			cnt = cnt + a[i] - a[j];
			if(cnt <= m) tot++;
			else{
				break;
			}
		}
		if(tot > ans) ans = tot;
	}
	cout << ans;
	return 0;
}