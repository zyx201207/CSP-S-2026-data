#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll num;
	char c;
}arr[200005];
ll pre[200005];
int n;
ll len;
vector<char> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	v.push_back('1');
	for(int i = 1; i <= n; i++){
		cin >> arr[i].num >> arr[i].c;
		len += arr[i].num;
		for(int j = 1; j <= arr[i].num; j++){
			v.push_back(arr[i].c);
		}
	}
	ll ans = 0;
	//cout << len << endl;
	for(ll i = 1; i <= len + 1 - i; i++){
		if(v[i] != v[len + 1 - i])ans++;
	}
	cout << ans;
	return 0;
}
