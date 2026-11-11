#include<bits/stdc++.h>
#include<cstdio>
#include<string>
long long n, a, x, sum = 0;
char c;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string y;
	cin >> n;
	for(long long i = 0; i < n; i++){
		cin >> a >> c;
		x += a;
		for(long long j = 1; j <= a; j++) {
		 	y += c;
		}
	}
	int k = x / 2, i = 0, j = x - 1;
	while(!(k <= 0)){
		k--;
		if(y[i] == y[j]){
		} else {
			y[j] = y[i];
			sum++;
		}
		i++;
		j--;
	}
	cout << sum;
	return 0;
}
