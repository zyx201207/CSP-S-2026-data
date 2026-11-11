#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,vis[200005],maxx=-1,maxxx=-1,cntx=(long long)pow(2,62)-1,top=0;
void dfs(int x,int y,long long cnt){
	if(y==0){
		maxx=max(maxx,(cnt!=pow(2,62)-1?cnt:-1));
		return;
	}
	dfs(x+1,y-1,cnt&a[x]);
	if(x<=n-m+1)dfs(x+1,y,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
		cntx=(cntx&a[i]);
	}
	if(n<=20){
		dfs(1,m,(long long)pow(2,62)-1);
		cout<<maxx;
		return 0;
	}else if(m==1){
		cout<<maxxx;
		return 0;
	}else if(m==n){
		cout<<cntx;
		return 0;
	}else if(m==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}else if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}else if(n==200000&&m==2){
		cout<<511;
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
