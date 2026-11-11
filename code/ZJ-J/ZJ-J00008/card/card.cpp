#include <bits/stdc++.h>
using namespace std;
int n,a[500005],cnt[300005],m,temp[500005],vis[300005];
char ch[2000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	int r=0;
	if(n>=2e5){
		for(int i=1;i<=n;++i){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;++i) cout<<cnt[i]<<' ';
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(vis[a[j]]){
				for(int k=vis[a[j]]+1;k<=r;++k){
					vis[temp[k]]=0;
				}
				r=vis[a[j]];
			}else{
				temp[++r]=a[j];
				vis[a[j]]=r;
			}
		}
		for(int j=1;j<=r;++j){
			cnt[temp[j]]++;
		}
		r=0;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;++i) cout<<cnt[i]<<' ';
	return 0;
}
