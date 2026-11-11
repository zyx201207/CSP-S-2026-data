#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,c[N],sum;
void dfs(int now,int add,int tot,int last){
	if(now>n){
		sum=max(sum,tot);
		return ;
	}
	if(now==1){
		dfs(now+1,add,1,c[1]);
	}
	else if(c[now]>c[now-1]){
		if(add>=tot*(c[now]-c[now-1])){
			dfs(now+1,add-tot*(c[now]-c[now-1]),tot+1,c[now]);
		} 
	}
	else{
		if(add>=c[now-1]-c[now]){
			dfs(now+1,add-c[now-1]+c[now],tot+1,last);
		}
	}
	dfs(now+1,add,tot,last);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(1,m,0,0);
	printf("%d",sum);
	return 0;
}
