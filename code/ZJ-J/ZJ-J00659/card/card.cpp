#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[5010],vis[3010],f[3010],x,j;
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) vis[j]=0;
		for(j=i;j<=n;j++){
			if(vis[a[j]]==0) q.push(a[j]),vis[a[j]]=1;
			else{
				x=0;
				while(x!=a[j]){
					x=q.top();q.pop();
					vis[x]=0;
				}
				q.push(a[j]);vis[a[j]]=1;
			}
		}
		while(q.size()){
			x=q.top(),f[x]++,q.pop();
		}
	}
	for(i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}