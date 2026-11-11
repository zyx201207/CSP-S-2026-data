#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m;
int a[N];
int b[N];
bool vis[N];
int id[N],cnt[N];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		int tot=0;
		memset(vis,0,sizeof(vis));
		memset(id,0,sizeof(id));
		for (int j=i;j<=n;j++) {
			b[++tot]=a[j];
		}
		for (int j=1;j<=tot;j++) {
			if (vis[b[j]]) {
			//	if (i==1) cout<<id[b[j]]<<' '<<j-1<<'\n';
				for (int k=id[b[j]];k<=j-1;k++) vis[b[k]]=0,id[b[k]]=0,b[k]=-1;
				id[b[j]]=j;
				vis[b[j]]=1;
			}
			else {
				vis[b[j]]=1;
				id[b[j]]=j;	
			}
			
		}
		for (int j=1;j<=tot;j++) {
		//	if (b[j]==-1) continue;
			cnt[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1

//3 1 2 1 3 2 3 1 2 1
//3 1 2 1
//3 1
