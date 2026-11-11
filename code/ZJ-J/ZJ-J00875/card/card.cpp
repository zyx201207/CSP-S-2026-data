#include<bits/stdc++.h>
using namespace std;
int n,m,top,vis[300005],a[500005],ans[300005],st[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			while(top>0&&vis[a[j]]){
				int x=st[top--];
				vis[a[x]]=0;
			}
			st[++top]=j;
			vis[a[j]]=1;
		}
		while(top>0){
			int x=st[top--];
			ans[a[x]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
