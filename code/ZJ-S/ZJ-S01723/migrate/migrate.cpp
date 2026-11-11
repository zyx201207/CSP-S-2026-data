#include <bits/stdc++.h>
using namespace std;
const int N=2*1e6;
int c,t,n,d,s;
int x[N],f[310][N];
void dfs(int k,int y){
	f[y][k]++;
	for(int i=k+1;i<=n;i++){
		if(x[i]-x[k]<=d){
			cout<<x[i]<<" "<<x[k]<<endl;
			dfs(i,y+(i-k));
		}
		else break;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		s=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		dfs(1,1);
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(f[j][i]!=0){
					if(f[j][i]==2) s++;
					for(int l=1;l<=n;l++) f[l][j]=0;
				}
			}			
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				f[j][i]=0;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
