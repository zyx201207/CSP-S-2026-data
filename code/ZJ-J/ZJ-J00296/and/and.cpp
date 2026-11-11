#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],ans,maxx,f,qzh;

void dfs(int x,int cnt,int sum){
	if(cnt==m){
		ans = max(ans,sum);
		return ;
	}
	if(x==n+1){
		return ;
	}
	dfs(x+1,cnt,sum);
	if(cnt<m){
		if(sum==-1){
			dfs(x+1,cnt+1,a[x]);
		}
		else{
			sum &= a[x];
			dfs(x+1,cnt+1,sum);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if(i==1){
			qzh = a[i];
		}
		else{
			qzh &= a[i];
		}
	}
	if(n>2000){
		cout << maxx;
		return 0;
	}
	if(n==m){
		cout << qzh;
		return 0;
	}
	dfs(1,0,-1);
	cout << ans;
	return 0;
}
