#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5+10,M = 505;
int n,m,c,d,q,w[N],a,aa,t,tt,x,y,last[M],nxt[M][N],minn=INT_MAX,vis[M][N];
void dfs(int ditiexian,int buxing,int weizhi,int yy){
//	cout<<ditiexian<<" "<<buxing<<" "<<weizhi<<" "<<yy<<endl;
	if(weizhi==yy){ minn=min(buxing+w[yy]+vis[ditiexian][weizhi],minn); return ;}
	for(int i=1;i<=n;i++){
		if(vis[i][weizhi]&&last[i]!=weizhi){
			if(ditiexian==0)  dfs(i,buxing+vis[i][weizhi],nxt[i][weizhi],yy);
			else{
				if(ditiexian==i) dfs(i,buxing,nxt[i][weizhi],yy);
				else dfs(i,buxing+vis[ditiexian][weizhi]+vis[i][weizhi],nxt[i][weizhi],yy);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>t,vis[i][a]=t,nxt[i][aa]=a,aa=a,tt=t;
		last[i]=a;
	}
//	cout<<q<<endl;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
//		cout<<x<<" "<<y<<endl;
		minn=INT_MAX;
		if(x==y){ cout<<0<<endl; continue;}
		dfs(0,w[x],x,y);
		cout<<minn<<endl;
	}
	return 0;
}
