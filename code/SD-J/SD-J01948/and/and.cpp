#include <bits/stdc++.h>
using namespace std;
long long n,m,s[200001],Max=0;
void dfs(long long a,long long cnt,long long num){
	if(cnt==m){
		Max=max(num,Max);
		return ;
	}
	if(a>n){
		return ;
	}
	if(cnt==0){
		dfs(a+1,cnt+1,s[a]);
		dfs(a+1,cnt,num);
		return ;
	}
	dfs(a+1,cnt+1,num&s[a]);
	dfs(a+1,cnt,num);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	dfs(1,0,1);
	printf("%d",Max);
	return 0;
}
