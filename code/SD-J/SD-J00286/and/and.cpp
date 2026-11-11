#include <bits/stdc++.h>
using namespace std;
int m,n;
long long a[200050],num = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m == n){
		cin >> a[1];
		num = a[1];
		for(int i = 2;i <= n;i++){
			cin >> a[i];
			num = num & a[i];
		}
		cout << num;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			num = max(num,a[i]);
		}
	}if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				num = max(num,a[i]&a[j]);
			}
		}
	}
	cout << num;
	return 0;
}
