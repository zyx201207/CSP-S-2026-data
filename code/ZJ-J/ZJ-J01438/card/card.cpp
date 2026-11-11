#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
bool flag[300005];
int p[300005];
int n,m;
void dfs(int s){
	if(s==n+1){
		for(int i=1;i<=m;i++){
			if(flag[i]==1) b[i]++;
		}
		memset(flag,0,sizeof(flag));
		return;
	}
	if(flag[a[s]]==1){
		for(int i=p[a[s]]+1;i<s;i++){
			flag[a[i]]=0;
		}
	}else{
		flag[a[s]]=1;
	}
	p[a[s]]=s;
	dfs(s+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
