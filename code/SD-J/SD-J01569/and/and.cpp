#include<bits/stdc++.h>
using namespace std;
int a[200010];
int ans,n,m;
/*void dfs(int num,int and_ans,int last) {
	if (num == m) {
		ans = max(ans,and_ans);
		return;
	}
	for (int i = last+1 ; i <= n ; i++) {
		if (num == 0) {
			dfs(num+1,a[i],i);
		} else {
			dfs(num+1,and_ans&&a[i],i);
		}
	}
	return;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	cout << a[n] && a[n-1];
	return 0;
}
