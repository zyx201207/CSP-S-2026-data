#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int ans[300005];
bool d[300005];
int z[300005], len;

void solve__1_12(){
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			while(d[a[j]]){
				d[z[len]] = 0;
				z[len--] = 0;
			}
			d[a[j]] = 1;
			z[++len] = a[j];
		}
		
		while(len){
			d[z[len]] = 0;
			ans[z[len]]++;
			len--;
		}
	}
}

void solve__13_14(){
	if(m == 1) ans[1] = n;
	else{
		ans[a[n]] = n;
		int cnt = 0;
		for(int i = n; i >= 1; i--, cnt++){
			if(a[i] != a[n]) continue;
		}
		int cnt1 = 0;
		bool have1 = 1;
		for(int i = n - cnt - 1; i >= 1; i--){
			if(a[i] == 2) have1 = 0;
			if(have1) cnt1++;
		}
		ans[2] = n - cnt - cnt1;
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n <= 5000) solve__1_12();
	else if(m <= 2) solve__13_14();
	else solve__1_12();
	
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	
	return 0;
}
