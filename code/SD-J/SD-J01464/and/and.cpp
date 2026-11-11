#include<iostream>
using namespace std;
int n,m,maxx=0;
int a[200005],vis[200005];
void dfs(int x,int cnt,int an){
	if(cnt==m){
		maxx=max(maxx,an);
		return;
	}
	if(an<maxx)return;
	if(cnt>m)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;		
			dfs(i,cnt+1,an&a[i]);
			vis[i]=0;
		}
	}
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
	}
	for(int i=1;i<=n;i++){
		dfs(1,0,a[i]);
	}
	dfs(1,0,a[1]);
	cout<<maxx;
	return 0;
}
