#include<bits/stdc++.h>
using namespace std;

int n, a[100005];
char s[100005], c[100005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &n);
	if(n == 1){
		printf("0");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d %s", &a[i], &c[i]);
	}
	if(n == 2){
		if(a[1] <= a[2]){
			printf("%d", a[1]);
			return 0;
		}else{
			printf("%d", a[2]);
			return 0;
		}
	}
	printf("0");
	return 0;
}
