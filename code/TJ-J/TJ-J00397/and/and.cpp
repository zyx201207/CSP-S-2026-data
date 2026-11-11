#include<stdio.h>
#include<stdlib.h>
int n,m,max,it[200005];
bool flag[200005];
void dfs(int now,int num){
	if(now = 0) max = __max(max,num);
	else for(int i = 0;i < n;i++){
		if(!flag[i]){
			flag[i] = true;
			dfs(now - 1,num & it[i]);
			flag[i] = false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;scanf("%d",&it[i]));
	dfs(m,0);
	printf("%d",max);
	return 0;
}
