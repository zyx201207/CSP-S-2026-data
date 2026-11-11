#include <bits/stdc++.h>
using namespace std;

const int LOG=19;
int n,m;
int op[300010];
int a[500010];
int f[500010][LOG+5];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		f[op[a[i]]][0]=i;
		op[a[i]]=i;
	}
	for(int i=1; i<=m; i++) op[i]=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=LOG; j++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=1; i<=n; i++){
		int pos=i;
		while(pos<=n){
			if(f[pos][0]==0){
				op[a[pos]]++;
				pos++;
				continue;
			}
			for(int j=LOG; j>=0; j--){
				if(f[pos][j]){
					pos=f[pos][j];
				}
			}
		}
	}
	printf("%d",op[1]);
	for(int i=2; i<=m; i++){
		printf(" %d",op[i]);
	}printf("\n");
	
	return 0;
}
