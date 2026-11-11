#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans;
inline void dfs(int d,int res,int choose){
	if(d==n+1){
		if(choose==m)ans=max(res,ans);
		return;
	}
	dfs(d+1,res&a[d],choose+1);
	dfs(d+1,res,choose);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(i+1,a[i],1);
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		cout<<maxx<<'\n';
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
	}else if(n==m){
		for(int i=2;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1]<<'\n';
	}
	return 0;
}
//11
//1111
