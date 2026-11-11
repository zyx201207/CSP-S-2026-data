#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000015], ans[1000015];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(i <= n){
			ans[i] = a[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(ans[i] != ans[i + 1] && i + 1 != 0){
			printf("%d ", ans[i]);
		}
	}
	return 0;
}
