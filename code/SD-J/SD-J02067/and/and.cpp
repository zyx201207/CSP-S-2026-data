#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int ans=-1;
int n,m;
int a[N];/*void dfs(int x,int cnt,int sum){
	if(x==n+1){
		ans=max(sum,ans);
		return ;
	}
	if(cnt==m+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(x+1,cnt,sum);
	for(int i=x+1;i<=n;i++){
		int res=sum&a[i];
		dfs(x+1,cnt+1,res);
	}
	return ;
}*/

int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<"\n";
		return 0;
	}
	cout<<a[n-m+1];
//	cout<<ans;
	return 0;
} 
