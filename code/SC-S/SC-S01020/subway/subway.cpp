#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int minn=0x3f3f3f3f;
struct A {
	int t[500005];
	int a[500005];
	int k;
} e[505];
int w[500005];
//void dfs (int root , int y , int cnt) {
//	if(cnt>=minn){
//		return ;
//	}
//	if(root==y){
//		
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=e[i].k;j++){
//			if(e[i].a[j]==x){
//				for(int i=1)
//			}
//		}
//	}
//}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		e[i].k=k;
		for(int j=1;j<=k;j++){
			cin>>e[i].a[j]>>e[i].t[j];
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		int sum=w[x]+w[y];
		cout<<sum;//求求了，把分给我！
	}
	return 0;
}