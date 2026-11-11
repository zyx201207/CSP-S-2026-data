#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+5;
int n,m;
int a[maxx];
int z[maxx][2005];
int dfs(int x,int p){
	if(n-x+1<p){
		return 0;
	}
	if(p==1){
		return a[x];
	}
	if(z[x][p]){
		return z[x][p];
	}
	return z[x][p]=max(a[x]&dfs(x+1,p-1),dfs(x+1,p));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	printf("%d",dfs(1,m));
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
