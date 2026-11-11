#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int n,m;
int b[N];
int ans[M];
int vis[M];
void os(int x){
	int now=x;
	memset(vis,0,sizeof(vis));
	memset(b,0,sizeof(b));
	for(int i=x;i<=n;i++){
		if(vis[a[i]]==0) vis[a[i]]=now,b[now]=a[i],now++;
		if(vis[a[i]]!=0){
			now=vis[a[i]]+1;
			for(int j=now;j<=n;j++) vis[b[j]]=0,b[j]=0;
		} 
	}
	for(int i=x;i<=now;i++){
		ans[b[i]]++;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		os(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
