#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long maxn = 0;
	long long minn = 1100000000;
	for(int i = 1;i <= n;i++){
		if(a[i] > maxn){
			maxn = a[i];
		}
		if(a[i] < minn){
			minn = a[i];
		}
	}
	cout << maxn-minn;
	return 0;
}
