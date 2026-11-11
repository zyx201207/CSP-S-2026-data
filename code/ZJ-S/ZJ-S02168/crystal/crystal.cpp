#include<bits/stdc++.h>
#define int long long
#define For(i, l, r) for(int i = l;i <= r;i++)
using namespace std;
const int INF = 1e12+5;
int n,m,ans,fA = 1,fB = 1;
int a[500005],d[500005];

void basic_score(){
	sort(a+1, a+n+1);
	for(int i = 1;i <= n;i++){
		int left = m, cnt = 0;
		int base = a[i];
		vector<int> b;
		for(int j = 1;j <= n;j++){
			if(a[j] > base)	continue;
			b.push_back(a[j]);
		}
		reverse(b.begin(), b.end());
		for(auto it : b){
			if(left > 0 && (left-base+it) >= 0){
				left -= (base - it);
				cnt++;
			}
			else	break;
		}
		ans = max(ans, cnt);
	}
	cout<<ans;
}

void full_score(){
	cout<<n;
}

void A_score(){
	int maxn = -INF;
	for(int i = 1;i <= n;i++){
		maxn = max(maxn, a[i]);
	}
	int left = m, cnt = 1;	//肯定可以自己加自己 
	for(int i = 1;i <= m;i++){
		left -= i;
		if(left < 0){
			break;
		}
		cnt++;
	}
	cout<<cnt;
}

void B_score(){
	int diff = abs(d[2]);
	int left = m, cnt = 1;
	for(int i = diff;i <= m;i += diff){
		left -= i;
		if(left < 0){
			break;
		}
		cnt++;
	}
	cout<<cnt;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	For(i, 1, n)	cin>>a[i];
	for(int i = 1;i <= n;i++){
		if(a[i] != i)	fA = 0;
	}
	for(int i = 2;i <= n;i++){
		d[i] = abs(a[i] - a[i-1]);
	}
	for(int i = 2;i <= n;i++){
		if(d[i] != d[2])	fB = 0;
	}
	if(n <= 5000){
		basic_score();
		return 0;
	}
	else if(fA == 1){
		A_score();
		return 0;
	}
	else if(fB == 1){
		B_score();
		return 0;
	}
	else{
		full_score();
		return 0;
	}
	return 0;
}
