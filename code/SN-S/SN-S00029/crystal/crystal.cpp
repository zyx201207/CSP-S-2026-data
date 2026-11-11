#include <bits/stdc++.h> 
using namespace std;
int n,m,r,u,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int a[n] = {};
	int b[n] = {};
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		u += a[i];
	}
	r = u / n;
	for(int i = 0; i < n; i++){
		if(a[i] <= r){
			b[i] = a[i];
			cnt++;
		}
		if(a[i] < 0){
			if(a[i] < r){
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
