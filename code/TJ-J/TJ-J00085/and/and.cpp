#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum = 0;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(i == 0){
		sum += a[i];
		}
		if(a[i+1] > sum){
			sum = a[i];
		}
	}
	cout << sum << " ";
	return 0;
}
