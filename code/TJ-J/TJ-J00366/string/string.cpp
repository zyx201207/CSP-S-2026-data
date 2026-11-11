#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	if(n==1){
		cout <<0;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	char t = c[1];
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		if(c[i]!=t)flag = 0;
	}
	if(flag==1){
		cout <<0;
		return 0;
	}
	int maxn = -1;
	for(int i = 1;i <= n;i++){
		maxn = max(maxn,a[i]);
	}
	if(maxn==1){
		cout <<n/2;
		return 0;
	}
	return 0;
}
