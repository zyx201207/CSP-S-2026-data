#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[2000010];
char c[200010];
long long int ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld %c", &a[i], &c[i]);
	}
	long long int i = 1, ic = a[1], j = n, jc = a[n];
	while(i < j){
		if(ic == 0){
			ic = a[++i];
		}
		if(jc == 0){
			jc = a[--j];
		}
		if(c[i] == c[j]){
			if(ic < jc){
				jc -= ic;
				ic = a[++i];
			}
			if(ic == jc){
				ic = a[++i];
				jc = a[--j];
			}
			if(ic > jc){
				ic -= jc;
				jc = a[--j];
			}
		}
		else if(c[i] != c[j]){
			if(ic > jc){
				ans += min(ic, jc);
				ic -= jc;
				jc = a[--j];
			}
			if(jc == ic){
				ans += jc;
				ic = a[++i];
				jc = a[--j];
			}
			if(ic < jc){
				ans += min(ic, jc);
				jc -= ic;
				ic = a[++i];
			}
		}
	}
	printf("%lld", ans);
	return 0;
} 
