#include<bits/stdc++.h>
using u = unsigned long long;
u n,m,a[500010],g,sum[2000];
bool b;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	scanf("%ull",&n);
	scanf("%ull",&m);
	for(int i = 1;i <= n;i++) scanf("%ull",&a[i]);
	g = a[2] - a[1];
	if(g == 0) printf("%d",n);
	sum[1] = 1;
	for(int i = 2;i <= 1400;i++) sum[i] = sum[i-1] + i;
	for(int i = 0;i <= 1400;i++){
		if(sum[i+1]*g > m && sum[i]*g <= m){
			printf("%d",i+1); 
		}
	}
	return 0;
} 
