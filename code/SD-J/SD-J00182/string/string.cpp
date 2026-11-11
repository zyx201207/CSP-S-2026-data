#include<bits/stdc++.h>
using namespace std;

int n;
long long a[2000001];
char c[2000001];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		bool b;
		scanf("%c", &b);
		scanf("%c", &c[i]);
	}
	int i, j;
	long long ans = 0;
	for( i = 1, j = n; i < j;){
		if(c[i] != c[j]){
			if(a[i] < a[j]){
				ans += a[i];
				a[j] -= a[i];
				a[i] = 0;
				i++;
			}
			else{
				if(a[j] <= a[i]){
					ans += a[j];
					a[i] -= a[j];
					a[j] = 0;
					j--;
				}
			} 
		}
		else{
			if(a[i] == a[j]){
				i++, j--;
			}
			else{
				if(a[i] < a[j]){
					i++;
					a[j] -= a[i];
				}
				else{
					a[i] -= a[j];
					j--;
				}
			}
		}
	}
	if(n %2 == 0){
		if(c[n /2] != c[n /2 + 1])
			ans += a[n / 2] + a[n / 2 + 1];
	}
	printf("%lld", ans);
	return 0;
}
