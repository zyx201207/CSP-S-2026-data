#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10,M=3e5;
int a[N],vis[N],num[M];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int k=1; k<=n; k++) {
		memset(vis,0,sizeof(vis));
		for(int i=k; i<=n; i++) {
			if(vis[a[i]]==1) {
				memset(vis,0,sizeof(vis));
			}
			vis[a[i]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j])num[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
