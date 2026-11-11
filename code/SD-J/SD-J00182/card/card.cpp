#include<bits/stdc++.h>
using namespace std;

int n, m;
int f[200001];
int b[200001], ans[200001], len;
int an[200001];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &f[i]);
	}
	for(int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		len = 0;
		for(int j = i; j <= n; j++){
			if(b[f[j]]){
				for(int k= b[f[j]] + 1; k <= len; k++){
					b[ans[k]] = 0;
				}
				len = b[f[j]];
			}
			else{
				ans[++len] = f[j];
				b[f[j]]  = len;
			}
			
		}
		for(int k = 1; k<= len; k++){
			an[ans[k]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", an[i]);
	}
	return 0;
}

