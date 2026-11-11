#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int maxn = 2e5+10;

int n, m;
int a[maxn];

//int dp[ ]

bool cmp(int a,int b){
	return a > b;
}

signed main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	int ans = a[1];
	for(int i = 2;i <= m;i++){
		ans = ans&a[i];
	}
	cout << ans;
	return 0;
}//证明了不对但我还是不死心 释怀了 
