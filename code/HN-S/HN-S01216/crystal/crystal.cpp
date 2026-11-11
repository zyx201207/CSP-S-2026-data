#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10, LG = 20;

int n, m;

int a[N];
int sum[N];

int lg[N];
int st[N][LG];

inline int read(){
	int x=0;char s=getchar(),ss=' ';
	while(!isdigit(s)) ss=s,s=getchar();
	while(isdigit(s)) x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return (ss=='-'?-x:x);
}

int qm(int l, int r){
	int klg = lg[r - l + 1];
	int x = max(st[l][klg], st[r - (1 << klg) + 1][klg]);
	
	return x;
}

bool check(int k){
//	cout << k << '\n';
	
	for(int l=1;l<=n - k + 1;l++){
		int r = l + k - 1;
		
		int cnt = (r - l + 1) * qm(l, r) - (sum[r] - sum[l - 1]);
		
//		cout << l << ' ' << r << ' ' << cnt << '\n';
		
		if(cnt <= m){
			return 1;
		}
	}
	
	return 0;
}

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	
	for(int i=1;i<=n;i++){
		a[i] = read();
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i=1;i<=n;i++){
		st[i][0] = a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	
	for(int i=2;i<=n;i++){
		lg[i] = lg[i >> 1] + 1;
	}

	for(int c=1;c<=lg[n];c++){
		for(int i=1;i<=n - (1 << (c - 1));i++){
			st[i][c] = max(st[i][c - 1], st[i + (1 << (c - 1))][c - 1]);
//			cout << st[i][c] << ' ';
		}
//		cout << '\n';
	}
	
		
	
	int l = 1, r = n;
	int ans = 1;
	
	while(l <= r){
		int mid = (l + r) >> 1;
		
		bool t = check(mid);
		
		if(t){
			l = mid + 1;
			
			ans = max(ans, mid);
		}
		else{
			r = mid - 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0;	
} 
