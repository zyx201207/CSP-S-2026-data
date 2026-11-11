#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[200005];
int ans;
bool f[200005];
void bfs(int k,int cnt){
	if(k==m){
		ans=max(ans,cnt);
		return ;
	}
	int c;
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		if(cnt==0)c=v[i];
		else c=cnt&v[i];
		f[i]=1;
		bfs(k+1,c);
		f[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&v[i]);
	}
	if(n==m){
		ans=v[1];
		for(int i=2;i<=n;i++){
			ans=ans&v[i];
		}
		cout<<ans;
	}else if(n<=12){
		bfs(0,0);
		cout<<ans;
	}else{
		sort(v+1,v+n+1);
		ans=v[n];
		for(int i=n-1;i>n-m;i--){
			ans=ans&v[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
