#include<bits/stdc++.h>
using namespace std;

int n,m,a[2000000],maxn = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1);
		maxn = a[n];
	}
	if(m == n){
		for(int i = 1; i<= n;i++){
			if(a[i+1] != 0){
				maxn = int(a[i]&a[i+1]);
			}
		}
	}
	if(m == 2){
		for(int i = 1; i<= n;i++){
			if(a[i+1] != 0){
				maxn = max(int(a[i]&a[i+1]),maxn);
			}
		}
	}
	cout << maxn;
	return 0;
}