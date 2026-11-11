#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
const int N = 2e5 + 10;
ll biao[32];
ll mypow(int a){
	ll ans = 1;
	while(a --){
		ans *= 2;
	}
	return ans;
}
int n,m;
ll qiu(int n,vector<ll> mj){
	if(n < 0){
		return 0;
	}
	int num = 0;
	vector<ll> k;
	for(int j = 0;j < mj.size();j ++){
		if(mj[j] & biao[n]){
			num ++;
			k.push_back(mj[j]);
		}
	}
	if(num >= m){
		return biao[n] + qiu(n - 1,k);
	}else{
		return qiu(n - 1,mj);
	}
}
void solve(){	
	cin >> n >> m;
	vector<ll> v(n + 1);
	ll ans = 0;
	for(int i = 0;i <= 31;i ++){
		biao[i] = mypow(i);
	}
	for(int i = 1;i <= n;i ++){
		cin >> v[i];
	}
	cout << qiu(31,v);
	return; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast;
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}
