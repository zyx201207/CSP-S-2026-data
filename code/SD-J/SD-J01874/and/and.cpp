#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
const int N=5e5+5;
ll n,a[N],ans,m,vis[N];
bool cmp(ll _,ll __){
	return _>__;
}
void dfs(ll now,int dep){
	if(dep==m){
		ans=max(ans,now);
		return ;
	}
	for(re int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(dep==0){
				now=a[i];
				dfs(now,dep+1);
				vis[i]=1;
			}else{
				vis[i]=1;dfs(now&a[i],dep+1);
				vis[i]=0;
			}
			
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(re int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
/*5 3
31 3 1 15 7*/
