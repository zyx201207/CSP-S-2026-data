#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long maxn;
long long a[200005];
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	cin >> n >> m;
	for(long long i=1; i<=n; i++){
		cin >> a[i];
	}
	for(long long i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j){
				maxn = max(maxn,a[i]&a[j]);
			}
		}
	}
	cout << maxn;
	return 0;
}