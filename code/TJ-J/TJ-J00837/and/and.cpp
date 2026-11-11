#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m,o,ans,num=2147483647;
bool b[N];
void dfs(int sum,int d){
	if(d==m){
		ans=max(ans,sum);
		return;	
	}
	for(int i=1;i<=n;i++){
		if(b[i]) continue;
		b[i]=true;
		dfs(sum&a[i],d+1);
		b[i]=false;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num&=a[i];
	}
	if(n==m) ans=num;
	else dfs(2147483647,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
