#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n,m,flag,ans;
ll a[N];
int yhyy(int x){
	int t[N] = {0};
	t[1] = x;
	for (int k = 1; k <= 2; k++){
		for (int i = 2; i <= n; i++){
			t[i] += t[i - 1];
		}
	}
	int j = 0;
	while (m - a[j + 1] >= 0){
		j++;
		m -= a[j];
	}
	return j; 
}
int solve(int beg){
	int temp = m,cnt = 1;
	for (int i = beg - 1; i >= 1; i--){
		if (temp - (a[beg] - a[i]) >= 0){
			temp -= (a[beg] - a[i]);
			cnt++;
		}
		else break;
	} 
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	for (int i = 2; i <= n; i++){
		if (a[i] - a[i - 1] == a[2] - a[1]) flag = 1;
		else{
			flag = 0;
			break;
		}
	}
	if (flag == 1){
		int gongcha = max(a[2] - a[1],a[1] - a[2]);
		ans = yhyy(gongcha);
		cout << ans;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for (int i = n; i >= 1; i--){
		ans = max(ans,solve(i));
	}
	printf ("%d",ans);
	return 0;
} 