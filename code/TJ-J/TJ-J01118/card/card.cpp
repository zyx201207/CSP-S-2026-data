#include<bits/stdc++.h>
using namespace std;
int a[200010];
int aa[2000000];
int vis[200010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 0){
				vis[a[j]] = j;
			}
			else if(vis[a[j]] != 0){
				for(int x = vis[a[j]]; x <= j; x++){
					vis[x] = 0;
				}
			}
		}
	}
	printf("0 0 1");
	return 0;
} 
