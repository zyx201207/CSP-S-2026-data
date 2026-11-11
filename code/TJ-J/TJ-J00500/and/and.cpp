#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200014],b[200014],d[200014],mx,c;
bool vis[200014];
void dfs(int k){
	if(c==k){
		long long t,o=0;
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=1;i<=c;i++){
			for(int j=1;j<=n;j++){
				if(b[i]==a[j]&&d[j]==0){
					o++;
					d[j]=1;
				}
			}
		}
		if(o==m){
			int x;
			for(int i=1;i<=n;i++){
				if(d[i]==1){
					x=i;
					t=a[i];
					break;
				}
			}
			for(int i=x+1;i<=n;i++)if(d[i]==1)t&=a[i];
			mx=max(mx,t);
		}
		c=0;
		for(int i=1;i<=c;i++)b[i]=0;
		dfs(m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			c++;
			b[c]=a[i];
			vis[i]=1;
			dfs(m);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(m); 
	cout<<mx;
	return 0;
}
