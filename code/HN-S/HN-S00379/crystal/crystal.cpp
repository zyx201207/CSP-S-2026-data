/*
小R是人类吗，这么简单都不会求，活着干啥 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(5e5 + 10)
Hahaha I AK IOI
ll aa[N], mx[25][N];
ll a[N], lg[N], n, m;

void init_lg(){
	for(int i = 1; i <= n; i++){
		lg[i] = lg[i / 2] + 1;
	}
}

void Segment_Table(){
	for(int i = 1; i <= n; i++){
		mx[0][i] = a[i];
	}
	for(int i = 1; i <= lg[n]; i++){
		for(int j = 1; j + (1 << i) - 1 <= n; j++){
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
		}
	}
}

ll q(int l, int r){
	int len = r - l + 1;
	int kk = lg[len] - 1;
	return max(mx[kk][l], mx[kk][r - (1 << kk) + 1]);
}

bool check(int i, int mid){
	if(i + mid - 1 > n){
		return 0;
	}	
	ll sum = aa[i + mid - 1] - aa[i - 1];
	ll need = q(i, i + mid - 1) * mid;
	return (need - sum <= m);
}

void work(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		aa[i] = aa[i - 1] + a[i];
	}
	init_lg();
	Segment_Table();
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll l = 0, r = n + 1;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if(check(i, mid)){
				l = mid;
			}else{
				r = mid;
			}
		}
		ans = max(ans, l);
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
