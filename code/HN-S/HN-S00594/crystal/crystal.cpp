#include<bits/stdc++.h>
using namespace std;
int cry[500005],m,n,ans=0;
inline int search(int x){
	int y=0;
	for(int j=1;j<=n;j++){
		if(cry[j]==x){
			y++;
		}
	}
	return y;
}
void dfs(int fix,int op,int now){
	if(fix>=m){
		if(ans<op){
			ans=op;
		}
		return;
	}
	for(int i=now;i<=n;i++){
		cry[i]++;
		dfs(fix+1,search(cry[i]),i);
		cry[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&cry[i]);
	}
	sort(cry+1,cry+n+1);
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
