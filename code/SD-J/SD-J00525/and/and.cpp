#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout << a[m];
	return 0;
}

