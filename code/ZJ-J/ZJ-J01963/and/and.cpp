#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans[25],now[25],cnt;
int b[200005][25],vis[200005][25];
void hit();
void dfs(int k,int nk){
	if(k==m){
		hit();
		return;
	}
	if(nk>n) return;
	if(n-nk>m-k){
	    dfs(k,nk+1);
	}
	for(int i=1;i<=cnt;i++){
		vis[nk][i]=now[i];
		now[i]=now[i]&&b[nk][i];
	}
	dfs(k+1,nk+1);
	for(int i=1;i<=cnt;i++){
		now[i]=vis[nk][i];
		vis[nk][i]=0;
	}
}
void hit(){
	for(int i=cnt;i>=1;i--){
		if(now[i]>ans[i]){
			for(int j=1;j<=cnt;j++) swap(ans[j],now[j]);
			return;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	memset(now,1,sizeof now);
	for(int i=1,j;i<=n;i++){
		cin>>a;
		j=0;
		while(a){
			j++;
			b[i][j]=a%2;
			a/=2;
		}
		cnt=max(cnt,j);
	}
	dfs(1,1);
	int n=0;
	for(int i=1,j=1;i<=cnt;i++,j*=2){
		n=ans[i]*j+n;
	}
	cout<<n;
	return 0;
}