#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],b[N],p[N];
char c[N];
int n,m,ans=0,now=0;
void dfs(int i,int k,int p){
	if(p==m){
		ans=max(ans,k);
		return ;
	}
	if(i>n+1){
		return ;
	}
	if(k==0){
		dfs(i+1,a[i],p+1);
		dfs(i+1,0,p);
	}else{
		dfs(i+1,k&a[i],p+1);
		dfs(i+1,k,p);
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
		//cout<<now<<endl;
		//ans=max(ans,now);
	cout<<ans<<endl;
	return 0;
} 
