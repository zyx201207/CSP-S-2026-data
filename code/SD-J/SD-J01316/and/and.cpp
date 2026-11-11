#include<iostream>
#include<vector>
#include<cstring> 

using namespace std;
typedef long long ll;
ll ans=-1;

int n,m;

ll a[200005];
void dfs(int dep,int k,ll val){
	if(dep==m){
		ans=max(ans,val);
		return ;
	}
	if(k==n){
		return ;
	} 
	dfs(dep+1,k+1,(val&a[k+1]));
	dfs(dep,k+1,val);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	ll fir=0;
	for(int i=0;i<=30;i++)	fir+=(1<<i);
	dfs(0,0,fir);
	cout<<ans;
	return 0;
}
