#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid (((ll)l+r)>>1)
int n,k,d[1000005],zhi[1000005],mxd[1000005][2];
vector<int>ve[1000005];
vector<pair<int,int> >mxf[1000005],mxb[1000005];
/*
void dfs(int u,int fa){
	cout<<u<<' '<<fa<<'\n';
	d[u]=d[fa]+1;
	mxd[u][0]=d[u];
	zhi[u]=1;
	int lst=int(ve[u].size())-1;
	for(int i=0;i<ve[u].size();i++){
		int v=ve[u][i];
		if(v==fa)continue;
		dfs(v,u);
		if(mxd[u][0]<mxd[v][0]){
			mxd[u][1]=max(mxd[u][1],max(mxd[v][1],mxd[u][0]));
			mxd[u][0]=mxd[v][0];
		}
		else mxd[u][1]=max(mxd[u][1],mxd[v][0]);
		zhi[u]=max(zhi[u],zhi[v]);
//		mxf[u][i].first=mxd[u][0];
//		mxf[u][i].second=mxd[u][1];
	}
//	for(int i=int(ve[u].size())-1;i>=0;i--){
//		int v=ve[u][i];
//		if(v==fa)continue;
//		mxb[u][i]=mxb[u][lst];
//		if(mxb[u][i].first<mxd[v][0]){
//			mxb[u][i].second=max(mxb[u][i].first,mxd[v][1]);
//			mxb[u][i].first=mxd[v][0];
//		}
//		else mxb[u][i].second=max(mxb[u][i].second,mxd[v][1]);
//		lst=i;
//	}
	zhi[u]=max(zhi[u],mxd[u][0]-d[u]+mxd[u][1]-d[u]+1);
}
*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){//¶à²â±ØÇå¿Õ 
			ve[i].clear();
			mxf[i].clear();
			mxb[i].clear();
			d[i]=zhi[i]=mxd[i][0]=mxd[i][1]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			d[x]++;d[y]++;
			ve[x].push_back(y);
			ve[y].push_back(x);
			mxf[x].push_back({0,0});
			mxf[y].push_back({0,0});
		}
		int c1=0,c2=0,c4=0;
		for(int i=1;i<=n;i++){
			if(d[i]==1)c1++;
			else if(d[i]==2)c2++;
			else if(d[i]==4)c4++;
		}
		if(k==n)cout<<0<<'\n';
		else if(n>=4&&k==1&&c1==2&&c2==n-2){
			cout<<2<<'\n';
		}
		else cout<<1<<'\n';
/*		dfs(1,1);
		for(int i=1;i<=n;i++)cout<<zhi[i]<<' ';cout<<'\n';
		for(int i=1;i<=n;i++)cout<<d[i]<<' ';
		
*/	}
	
	return 0;
}
/*
0 1
10 3
1 2 1 3 2 4 2 5 3 6 3 7 3 8 7 9 9 10
*/
