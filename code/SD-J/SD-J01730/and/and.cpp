#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll a[200005],ans,n,k,path[200005];
void dfs(int id,int u,ll cnt){
	if(u==0){ans=max(ans,cnt);return ;}
	if(id>n){return ;}
	if(cnt==-1){
		dfs(id+1,u,-1);
		dfs(id+1,u-1,a[id]);
	}
	else{
		dfs(id+1,u,cnt);
		dfs(id+1,u-1,(cnt&a[id]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	ll maxx=0;
	if(k==1){
		for(int i=1;i<=n;++i)maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	} 
	dfs(1,k,-1); 
	cout<<ans;
	return 0;
}
