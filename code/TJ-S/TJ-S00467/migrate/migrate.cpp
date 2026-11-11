#include <iostream>
#include <cstdio>
using namespace std;

#define N 5005

int n,d,a[N];
int g[N][N],f[N][N];

void solve(){
	scanf("%d %d",&n,&d);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i] - a[j] <= d && a[j] - a[i] <= d){
				g[i][j] = 1;
			}
			cout << g[i][j] << ' ';
		}
		putchar('\n');
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(g[i][k] + g[k][j] < g[i][j]){
					g[i][j] = g[i][k] + g[k][j];
					f[i][j] = 0;
				}
				if(g[i][k] + g[k][j] == g[i][j]) f[i][j]++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << f[i][j] << ' ';
		}
		putchar('\n');
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(f[i][j] == 2){
				ans++;
			}
		}
	}
	printf("%d\n",ans / 2);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--) solve();
	return 0;
}
