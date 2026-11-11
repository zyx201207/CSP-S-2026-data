#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}

	if(n > 2000){
		sort(a+1,a+n+1,cmp);
		int ans = a[1];
		for(int i = 2;i <= m;i ++){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}

	int maxm = -1;

	for(int i = 1;i <= n-m+1;i ++){
		int base = a[i];
		bool vis[200005];
		memset(vis,0,sizeof vis);
		vis[i] = true;
		for(int j = 1;j < m;j ++){
			int maxn = -1,dw = -1;
			for(int k = i+1;k <=n;k++){
				if(vis[k])continue;
				int tp = base & a[k];
				if(tp > maxn){
					maxn = tp;
					dw = k;
				}
			}
			vis[dw] = true;
			base = base & a[dw];
		}
		maxm = max(maxm,base);
	}

	cout << maxm << '\n';

	return 0;
}