#include<bits/stdc++.h>
using namespace std;
int sss,m,n,q,aa,bb,w[505],vis[505],d,aaa,bbb;
int nti[505][505],arr[505][505],mi=0;
void dfs(int x,int t) {
	if(x==bb) {
		if(mi==0) {
			mi=t+w[bb];
		} else mi=min(t,mi)+w[bb];
		return ;
	}

	if(vis[x]==1) {
		return ;
	}
	if(x==aa) {
		vis[x]=1;
		for(int i=0; i<n; i++) {
			if(arr[i][x]!=0) {
				dfs(arr[i][x],nti[x][i]+nti[i][arr[i][x]]);

			}

		}
		vis[x]=1;
		return ;
	}
	vis[x]=1;

	for(int i=0; i<n; i++) {
		if(arr[i][x]!=0) {
			dfs(arr[i][x],t+nti[arr[i][x]][i]+nti[x][i]);

		}

	}
	vis[x]=0;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>sss>>n>>m>>d>>q;
	for(int i=0; i<m; i++) {
		cin>>w[i];
	}
	for(int i=0; i<n; i++) {
		cin>>sss;
		for(int i=0; i<sss; i++) {
			cin>>aaa>>bbb;
			arr[i][aaa]=1;
			nti[aaa][i]=bbb;

		}
	}
	for(int i=0; i<q; i++) {
		cin>>aa>>bb;
		dfs(aa,w[aa]);
		cout<<mi<<"\n";
		mi=0;
	}
	return 0;
}
