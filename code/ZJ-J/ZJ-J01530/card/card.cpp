#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],vis[N],p[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		memset(vis,0,sizeof vis);
		queue<int> q;
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==1){
				int u=q.front();q.pop();
				while(u!=a[i]){
					u=q.front();q.pop();
				}
			}
			q.push(a[i]);
			vis[a[i]]=1;
		}
		while(q.size()){
			int u=q.front();q.pop();
			p[u]++;
		}	
	}
	for(int i=1;i<=m;i++) cout<<p[i]<<" ";
}
