//想上luogu CSP-S 2026 HN迷惑行为大赏
//能不能放一下我qwq
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[405],a[405][205],t[405][205],ans;
void dfs(int x,int to,int sum){
	if(x==to)ans=min(ans,sum+w[to]);
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[k][i]>>t[k][i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ans=0x3f3f3f3f;
		cin>>x>>y;
		dfs(x,y,w[x]);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
