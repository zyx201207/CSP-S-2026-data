#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int a[N],pre[N];
int n,m;
bool check(int x){
	for(int i = x + 1;i <= n;i++){
		if(a[i] * x - (pre[i - 1] - pre[i - 1 - x]) <= m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1 ,a + n + 1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	int l = 0,r = n - 1;
	while(l + 1 < r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	} 
	if(check(r)) cout << r + 1 <<"\n";
	else if(check(l)) cout << l + 1<<"\n";
	return 0;
}
