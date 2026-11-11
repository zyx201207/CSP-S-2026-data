#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],v[200005];
long long maxx;
void dfs(int k,int s,long long ans){
	if(s==m){
		maxx=max(maxx,ans);
		cout<<ans<<" "<<maxx<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			if(ans==0)ans=a[i];
		    else ans=ans&a[i];
			v[i]=1;
			dfs(i,s+1,ans);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<maxx;
	}
	return 0;
}
