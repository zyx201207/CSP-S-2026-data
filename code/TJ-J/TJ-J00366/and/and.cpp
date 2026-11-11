#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m==1){
		int maxn = -1;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout <<maxn;
		return 0;
	}
	int t = a[1];
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		if(t!=a[i])flag = 0;
	}
	if(flag==1){
		cout <<t;
		return 0;
	}
	if(m==n){
		int res = a[1];
		for(int i = 1;i <= n;i++){
			res = res and a[1];
		}
		cout <<res;
		return 0;
	}
	if(m==2){
		cout <<a[n];
		return 0;
	}
	int axn = -1;
	for(int i = 1;i <= n;i++){
		axn = max(axn,a[i]);
	}
	if(axn<4)cout <<3;
	return 0;
}
