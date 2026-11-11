#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[200005],ans,n,m;
bool dis[200005];
void dfs(int u,int cnt){
	if(u==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(dis[i]==false){
			dis[i]=true;
			if(u==0){
				dfs(u+1,a[i]);
			}else{
				int op=cnt;
				op&=a[i];
				dfs(u+1,op);
			}
			dis[i]=false;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
