#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, m, sum, ans, maxn, last, a[N], b[N];
bool flag = false, flagb = true;
void solve(int k, int mm){
	int cnt = 0;
	memset(b, 0, sizeof(b));
	if(flagb == true){
		int op = a[2] - a[1];
		int qo = 0, l = 1;
		while(mm >= 0){
		    qo = l * op, l++;
			if(mm >= qo) mm -= qo, cnt++;
			else break;	
		}
		cnt++;
		cout << cnt << '\n';
	}
	else{
		for(int i = 1; i <= k; i++) b[i] = abs(a[i] - a[k]);
	    for(int i = k; i >= 1; i--){
		    if(mm >= b[i]) cnt++, mm -= b[i];
		    else break;
	    }	
		if(cnt < last) flag = true;
	    else last = cnt, maxn = max(maxn, cnt);
	}
	return ;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	//Ãÿ ‚–‘÷ A°¢B 
	flagb = true;
	int ui = a[2] - a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] != ui){
			flagb = false;
			break;
		}
	}
    sort(a + 1, a + n + 1);
    int jk = (n + 1) / 2;
    int kl = a[jk];
    for(int i = jk + 1; ; i++){
    	if(a[i] == kl) jk++;
    	else break;
	}
	if(flagb == true){
		solve(jk, m);
		return 0;
	}
    for(int kk = jk; kk <= n; kk++){
    	solve(kk, m);
    	if(flag == true){
    		cout << maxn << '\n';
    		return 0;
		}
	}
    cout << maxn << '\n';
	return 0;
}
//Oct31==Dec25?
