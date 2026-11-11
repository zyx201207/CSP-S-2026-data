#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],vis[N],ans[N],mx[N],nxt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mx[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		nxt[i]=mx[a[i]]+1;
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i=nxt[i]){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}