#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005] = {},q[200005] = {},h[200005] = {},ans = 0,s[5] = {};
bool f1 = true,f2 = true,f3 = true,b[200005] = {};

bool check(int x){
	for(int i = 0;(1 << i) <= x;i++){
		if((1 << i) == x){
			return true;
		}
	}
	return false;
}

void dfs1(int x,int y,long long sum){
	if(y == 0){
		ans = max(ans,sum);
		return ;
	}
	if(x > n) return ;
    dfs1(x + 1,y - 1,sum & a[x]);
    dfs1(x + 1,y,sum);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    q[0] = (1 << 30) - 1;
    h[n + 1] = (1 << 30) - 1;
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	if(a[i] > 4) f1 = false;
    	b[i] = check(a[i] + 1);
    	if(!b[i]) f2 = false;
		if(a[i] != i - 1) f3 = false;
		q[i] = q[i - 1] & a[i];
	}
	b[0] = check(n);
	for(int i = n;i >= 1;i--){
		h[i] = h[i + 1] & a[i];
	}
	if(b[0] && f3){
    	ans = (1 << 30) - 1;
    	for(int i = n;i >= n - m + 1;i--){
    		ans &= a[i];
		}
		cout << ans;
	}
	else if(f2){
		sort(a + 1,a + n + 1);
		ans = (1 << 30) - 1;
    	for(int i = n;i >= n - m + 1;i--){
    		ans &= a[i];
		}
		cout << ans;
	}
	else if(m == 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout << ans;
	}
	else if(m == n){
		cout << q[n];
	}
	else if(m == 2){
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else if(m == n - 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans,q[i - 1] & h[i + 1]);
		}
		cout << ans;
	}
	else if(n <= 20){
		dfs1(1,m,(1 << 30) - 1);
		cout << ans;
	}
	else if(f1){
		for(int i = 1;i <= n;i++){
			s[a[i]]++;
		}
		if(s[4] >= m) cout << 4;
		else if(a[3] >= m) cout << 3;
		else if(a[3] + a[2] >= m) cout << 2;
		else if(a[3] + a[1] >= m) cout << 1;
		else cout << 0;
    }
    return 0;
}