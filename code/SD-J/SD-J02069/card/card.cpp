#include<bits/stdc++.h>
using namespace std;
int n,m,a[611111],ans[611111],v[611111],vis[611111];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int cnt=0;
		for(int j=i; j<=n; j++) {
			if(vis[a[j]]!=0) {
				int temp=cnt;
				for(int x=vis[a[j]]+1; x<=temp; x++) {
					
					vis[v[x]]=0;
					v[x]=0;
					cnt--;
				}
			} else {
				cnt++;
				v[cnt]=a[j];
				vis[a[j]]=cnt;
			}
		}
		for(int j=1; j<=cnt; j++) {	
			ans[v[j]]++;
			vis[j]=0;
			v[j]=0;
		}
		for(int j=1; j<=m; j++) {
			v[j]=0;
			vis[j]=0;
		}
	}
	for(int i=1; i<=m; i++)cout<<ans[i]<<' ';
	return 0;
}
