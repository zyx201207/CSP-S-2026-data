#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[200005],b[5000005],w,mx=-1;
bool u[200005];
void dfs(int pos){
	if(pos>m){
		int t=a[p[1]];
		for(int i=2;i<=m;i++) t&=a[p[i]];
		b[w++]=t;
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			p[pos]=i;
			dfs(pos+1);
			u[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	for(int i=1;i<=w;i++) mx=max(b[i],mx);
	cout<<mx;
	return 0;
}
