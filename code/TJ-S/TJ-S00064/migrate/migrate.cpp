#include<bits/stdc++.h>
using namespace std;
int n,a[25],ans;
void dfs(int st,int sum){
	if(st>n){
	ans=max(ans,sum);
	return;
	}
	dfs(st+1,sum+a[st]);dfs(st+1,sum);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&n);
	for(int i =1;i <= n;i++)scanf("%d",&a[i]);
	if(n<=20){dfs(1,0);printf("%d",ans);}
	else printf("0");
	fclose(stdin);fclose(stdout); 
	return 0;
}
