#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
const int N = 2e5 + 10;
int l = 1,r = 0;
pic v[N];
void solve(){
	string s;
	int n;
	ll he = 0,ans = 0;
	cin >> n;
	int m;
	char c;
	while(n --){
		cin >> m >> c;
		he += m;
		v[++r] = {m,c};
	}
	while(r - l > 0){
		int num1 = v[l].first,num2 = v[r].first;
		if(v[l].second != v[r].second){
			ans += min(num1,num2);
		}
		if(num1 != num2){
			if(num1 < num2){
				l ++;
				v[r].first -= num1;
			}else{
				r --;
				v[l].first -= num2;
			}
		}else{
			l ++;
			r --;
		}
	}
	cout << ans;
	return; 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fast;
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
	return 0;
}
