#include<bits/stdc++.h>
#include<cstdio>
long long n, m, a[300009], sum;
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int max1 = 0, max2;
	while(m--){
		for(int i = 1; i <= n; i++){
			if(a[i] > max1){
				max1 = a[i];
				max2 = i;
			}
		}
		if(sum == 0){
			sum = max1;
			a[max2] = 0;
		} else {
			sum and max1;
			a[max2] = 0;
		}
		max1 = 0;
		max2 = 0;
	}
	cout << sum << endl;
	return 0;
}
