#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sta[500010];
int vis[300010];
int v[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int top=0;
		for(int j=i; j<=n; j++) {
			if(vis[a[j]]==0) {
				sta[++top]=a[j];
				vis[a[j]]=1;
			} else {
				while(top&&sta[top]!=a[j]) {
					vis[sta[top]]=0;
					top--;
				}
			}
		}
		while(top) {
			v[sta[top]]++;
			top--;
		}
		for(int j=1; j<=m; j++) {
			vis[j]=0;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<v[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}
