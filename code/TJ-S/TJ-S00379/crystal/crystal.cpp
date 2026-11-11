#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	long long num;
	cin >> n >> m;
	int a[n+5];

	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}

	for(int i = 1;i <= n;i++){
		for(int j = 1;j < n;j++){
			if(a[j] > a[j+1]){
				num = a[j];
				a[j] = a[j+1];
				a[j+1] = num;
			}
		}
	}

	for(int i = 1;i <= m;i++){
		a[1] += 1;
		for(int j = 1;i <= n;j++){
			if(a[j] > a[j+1]){
				num = a[j];
				a[j] = a[j+1];
				a[j+1] = num;
			}
			else break;
		}
	}
	
	long long max = 1;
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i+1]){
			max += 1;
		}
		else break;
	}

	cout << max;
	return 0;
}
