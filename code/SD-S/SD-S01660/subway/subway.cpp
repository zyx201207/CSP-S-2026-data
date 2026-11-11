#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	int w;
}a[5][10000001];
bool vis[1000001]={0};
int b[100001];
int vis1[1000001];
	int vis2[1000001];
	int c[1000001];
int main () {
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	int c1,n,m,d,q;
	cin>>c1>>n>>m>>d>>q;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		int m1;
		cin>>m1;
		for(int j=1;j<=m1;j++){
			cin>>a[i][j].s>>a[i][j].w;
			if(i==1){
				vis[a[i][j].s]=1;
				vis1[a[i][j].s]=a[i][j].w;
			}else{
				if(vis[a[i][j].s]!=0){
					b[++cnt]=a[i][j].s+vis1[a[i][j].s];
					vis2[a[i][j].s]=a[i][j].w;
				}
			}
		}
	}
	sort(b+1,b+cnt+1);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(vis[x]!=0&&vis[y]!=0){
			cout<<vis1[x]+vis1[y]+c[x]+c[y];
		}else if(vis[x]==0&&vis[y]==0){
			cout<<vis2[x]+vis2[y]+c[x]+c[y];
		}else{
			if(vis[x]==0){
				cout<<b[1]+vis2[x]+vis2[y]+c[x]+c[y]<<endl;
			}else{
				cout<<b[1]+vis2[x]+vis2[y]+c[x]+c[y]<<endl;
			}
		}
	}
	return 0 ;
}

