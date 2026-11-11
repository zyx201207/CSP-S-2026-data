#include<bits/stdc++.h>
using namespace std;
int n, m, a[2010], f[2010][2010];
int yu(int a, int b){
	int a1[100], a2[100], a3[100], a4[100], a5[100], a6[100];
	int i1 = 0, i2 = 1;
	while(a >= 1){
		
		a2[i2] = a % 2;
		i2++;
		a /= 2;
	}
	for(int j = i2 - 1; j >= 1; j--){
		i1++;
		a1[i1] = a2[j];
	}
	int i3 = 0, i4 = 1;
	while(b >= 1){
		
		a4[i4] = b % 2;
		i4++;
		b /= 2;
	}
	for(int j = i4 - 1; j >= 1; j--){
		i3++;
		a3[i3] = a4[j];
	}
	for(int i = 1; i <= max(i1, i3); i++){
		a5[i] = a1[i] && a3[i];
	}
	for(int i = max(i1, i3); i >= 1; i--){
		a6[i] = a5[max(i1, i3) - i + 1];
	}
	long long s = 0;
	for(int i = 1; i <= max(i1, i3); i++){
		long long sum = 1;
		for(int j = 2; j <= i; j++){
			sum *= 2;
		}
		s+=a6[i] * sum;
	}
	return s;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int kl=a[1];
	if(m==n){
		for(int i = 1; i <= n; i++){
			kl = yu(kl,a[i]);
		}
		cout << kl;
	}
	if(m == 1){
		int maxx = 0;
		for(int i = 1; i <= n; i++){
			maxx = max(maxx, a[i]);
		}
		cout << maxx;
	}
	if(m == 2){
		int maxx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i =!j){
					maxx = max(maxx, yu(a[i], a[j]));
				}
			}
		}
		cout << maxx;
	}
	return 0;
}

