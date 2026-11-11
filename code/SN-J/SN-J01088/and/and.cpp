#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans=0;
void dfs(int x,int cnt,int p){
	if(cnt<=ans){
		return;
	}
	if(p==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=x+1;i<=n;i++){
		
		dfs(i,cnt&a[i],p+1);
	}
	
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<ans;
	return 0;
}


