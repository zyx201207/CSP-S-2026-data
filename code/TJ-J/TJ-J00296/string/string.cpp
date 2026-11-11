#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 220000;
int n, a[N], pre[N], ans = 0;
int t = 0, i1, j1;
char c[N];

char find1(int pos){
	int l = 0, r = n, m;
	while(l<=r){
		m = (l+r) >> 1;
		if(pre[m] >= pos) r = m - 1;
		else l = m + 1;
	}
	return c[l];
}

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//读入 
	cin >> n;
	pre[0] = 1;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> c[i];
		pre[i] = pre[i-1] + a[i];
		t += a[i];
	}
	//处理指针位置 
	int mid = (1+t)>>1;
	if(t&1){
		i1 = mid; j1 = mid;
	}else{
		i1 = mid; j1 = mid++;
	} 
	//双指针计算答案
	for(int i=i1,j=j1; i>=1 && j<=t; i--,j++){ 
		if(find1(i+1)!=find1(j+1)) ans++;
	}
	//输出 
	cout << ans;
	return 0;
}
