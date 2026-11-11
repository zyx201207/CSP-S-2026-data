#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[500005],t[500005],vis[500005],k[505],x,y,vvis[500005];
struct A{
	int ed,ti;
}xfb;
vector<A>G[500005];
int zdl(int x,int y){
	int zx=INT_MAX,s=x,a=0,flag=1;
	memset(vis,127,sizeof(vis));
	memset(vvis,0,sizeof(vvis));
	vis[x]=0;
	while(flag){
		vvis[s]=1;
		flag=0;
		for(int i=0;i<G[s].size();i++)vis[G[s][i].ed]=min(vis[G[s][i].ed],vis[s]+G[s][i].ti);
		zx=INT_MAX;
		for(int i=1;i<=m;i++){
			if(vis[i]<zx&&vvis[i]==0){
				zx=vis[i];
				s=i;
				flag=1;
			}
		}
	}
	return vis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			for(int k=1;k<j;k++)xfb.ed=a[k],xfb.ti=t[j]+t[k],G[a[j]].push_back(xfb),xfb.ed=a[j],G[a[k]].push_back(xfb);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<zdl(x,y)+w[x]+w[y]<<"\n";
	}	
}
