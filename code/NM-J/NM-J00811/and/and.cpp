#include<bits/stdc++.h>
using namespace std;
int n,m,q[200010],maxn = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> q[i];
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			int op = q[i] & q[j];
			maxn = max(op,maxn);
		}
	}
	cout << maxn;
	return 0;
}
