#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500006];
int vis[300006];
int ans[300006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		vis[a[i]]--;
		if(vis[a[i]]) continue;
		int ok=0;
		for(int j=i;j>=1;j--){
			if(vis[a[j]]) ok=1;
			if(ok==0 or a[i]==a[j]) ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
