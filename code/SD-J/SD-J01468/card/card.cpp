#include<bits/stdc++.h>
using namespace std;
long long n,m,b[200005],a[200005],vis[300005],ans[300005],r,sst[200005]; 
void dfs(long long num){
	if(num==0)return;
	int cnt=0;
	for(int i=1;i<=num;i++){
		if(vis[a[i]]!=0){
			while(sst[r]!=a[i]){
				b[++cnt]=sst[r];r--;
			}
			b[++cnt]=sst[r];
			r--;
		}
		sst[++r]=a[i];
		vis[a[i]]=i;
	}
	for(int i=1;i<=cnt;i++){
		a[i]=b[i];
	}
	while(r>=0){
		ans[sst[r]]++;
		r--;
	} 
	memset(vis,0,sizeof vis);
	dfs(cnt);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(n);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
