#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m; 
int a[500010];
int sum[500010]; 

bool cheek(int mt){
	
	for(int i = mt;i <= n;i ++) {
		if(a[i] * mt - (sum[i] - sum[i - mt]) <= m) return true;
	}
	
	return false;
}

int bs(){
	int l = 0, r = n;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(cheek(m)){
			l = m;
		}else{
			r = m - 1;
		}
	} 
	return l;
}


signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++) sum[i] = a[i] + sum[i - 1];
	
	cout << bs();
	
	return 0;
}
//1 10 11 12

