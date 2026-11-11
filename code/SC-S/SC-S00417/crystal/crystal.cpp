#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(0)
using namespace std;

const int N = 5e3 + 5;

int n, m, sum, ans;
int a[N], gm[N][N], g[N][N];

void mi(int n, int m){
	
	for(int i = 1;i <= n;i ++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			gm[i][j] = a[j] - a[i]; 
		}
	}
	
	for(int i = 1;i <= n;i ++){//从 i 到 j 变为相同 
		for(int j = i;j <= n;j ++){
			g[i][j] = g[i][j - 1] + (a[j] - a[j - 1]) * (j - i);
//			cout << g[i][j] << ' ';
		}
//		cout << "\n";
	}
	
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			if(g[i][j] <= m) ans = max(ans, j - i + 1);
		}
	}
	
	cout << ans;
}


int b[N * 100], ch[N * 100];

void mx(int n, int m){
	for(int i = 1;i <= n;i ++){
		cin >> b[i];
	}
	sort(b + 1, b + 1 + n);
	int ca = b[2] - b[1];
	for(int i = 1;i <= n;i ++){
//		cout << (ca + ca * (i - 1)) * (i - 1) / 2 << ' ';
		if(m < (ca + ca * (i - 1)) * (i - 1) / 2){
			cout << i - 1;
			break;
		} 
	}
}

signed main(){
	ios;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(n <= 5000){
		mi(n, m);
	}else{
		mx(n, m);
	}

//	mx(n, m);
	return 0;
}