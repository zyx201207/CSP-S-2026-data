#include<bits/stdc++.h>

#define ll long long
#define int ll

int read(){
	int val = 0, ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
		val = (val << 3) + (val << 1) + (ch ^ 48);
		ch = getchar();
	}
	return val;
}

using namespace std;

const int MOD = 1e9 + 7;

void Add(int &x, int y){x += y; if(x >= MOD) x -= MOD;}
void Sub(int &x, int y){x -= y; if(x < 0) x += MOD;}

const int MAXN = 5e5 + 5;

ll n, m, cnt, ans;
ll a[MAXN];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1, j = 1; i <= n; i++){
		cnt += (i - j) * (a[i] - a[i - 1]);
		while(j < i && cnt > m){
			cnt -= a[i] - a[j];
			j++;
		}
		ans = max(ans, (ll)i - j + 1);
	}
	cout << ans;

	return 0;
}

