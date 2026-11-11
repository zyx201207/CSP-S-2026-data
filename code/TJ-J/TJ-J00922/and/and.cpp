#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[10000015];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= n; j++){
			if(a[j] <= a[j + 1] && j + 1 <= n){
				swap(a[j], a[j + 1]);
			}
		}
	}
	if(a[1] == a[2]){
		printf("%d", a[1]);
		return 0;
	}else{
		printf("%d", a[n - 1]);
		return 0;
	}
	return 0;
}
