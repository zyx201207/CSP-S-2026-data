#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005],k[505],x[500005];
struct node{
	int a[500005],t[500005];
}sub[505];
void dfs(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++)
			cin>>sub[i].a[j]>>sub[i].t[j];
	}
	while(p--){
		int b,e;
		cin>>b>>e;
		dfs();
	}
	return 0;
}
