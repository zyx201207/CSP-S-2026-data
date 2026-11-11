#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	bool flag = true;
	for(int i = 1;i <= n;i++){
		if(a[i] != i) flag = false;
	}
	bool flag1 = true;
	long long t;
	for(int i = 1;i <= n;i++){
		if(i == 1){
			t = a[2] - a[1];
		}else{
			if(a[i] - a[i-1] != t) flag1 = false; 
		}
	}
	if(flag){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			m -= i;
			if(m >= 0) ans++;
			else break;
		} 
		cout << ans;
	}else if(flag1){
		//2 4 6 8 10
		int ans = 0;
		for(int i = a[2] - a[1];i <= n * a[2] - a[1];i *= a[2] - a[1]){
			m -= i;
			if(m >= 0) ans++;
			else break;
		} 
		cout << ans;
	}
	return 0;
}
