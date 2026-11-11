#include<bits/stdc++.h>
using namespace std;
const int N=502;
const int M=5e5+2;
struct node{
	int s,t;
}a[N];
int c,n,m,d,q;
int w[M];
int vis[M];
int v[M];
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
			int b;
			cin>>b;
			cin>>a[b].t;
			a[b].s=k;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+a[x].t+a[y].t<<"\n";
	}
	return 0;
}
