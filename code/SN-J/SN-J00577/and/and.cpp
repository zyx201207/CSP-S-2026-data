#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
ll n, m, a[maxn];
string two[maxn];
ll maxx = -1;
void to_two(int x, int i){
	while(x){
		int m = x % 2;
		char th = m + '0';
		two[i] += th;
		x /= 2;
	}
	ll len = two[i].size();
	maxx = max(maxx, len);
	for(int j = 0;j < len / 2;j++)
		swap(two[i][j], two[i][len - 1 - j]);
}
void len_together(){
	for(int i = 1;i <= n;i++){
		int len = two[i].size();
		for(int j = 1;j <= maxx - len;j++)
			two[i] = '0' + two[i];
	}
}
bool cmp(int x, int y){
	return x >= y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1;i <= n;i++){
		to_two(a[i], i);
	}
	len_together();
	for(int j = 0;j < maxx;j++){
		int cnt = 0;
		deque<int> g;
		for(int i = 1;i <= n;i++){
			if(two[i][j] == '1')
				cnt++, g.push_back(i);
		}
		if(cnt < m)
			continue;
		else{
			ll ans = a[g.front()];
			m--;
			g.pop_front();
			while(m--){
				ans &= a[g.front()];
				g.pop_front();
			}
			cout<<ans<<"\n";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}
//±³°ü?
//O(nlogn)!!! 
//CCF = Chinese Can FLY!!! = CPL Can FLY!!!!!!!
