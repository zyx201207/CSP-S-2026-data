#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[n+5][m+5],t[n+5][m+5];
int w[m+5],a[m+5],b[m+5];
int ans=0;
void dfs(int a,int b){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=a){
				ans+=t[i][j];
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
		ans+=w[a[i]];
		ans+=w[b[i]];
		dfs(a[i],b[i]);
	}
	return 0;
}