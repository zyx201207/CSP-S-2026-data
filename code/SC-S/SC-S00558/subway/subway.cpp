#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct site{
	int t1;//表示从每个地铁站的地铁口走到站厅需要的时间。
	int nb;//每个节点有几条线路
	int nt[25];//相邻的站有那些
};
site a[514514];
int sz=0;
int minn=1e18;
int my[514514];
void dfs(int ed,int id,int mi){
	if(id==ed){
		minn=min(minn,mi);
		return;
	}
	for(int i=0;i<a[id].nb;i++){
		if(my[a[id].nt[i]]==1)continue;
		my[a[id].nt[i]]=1;
		dfs(ed,a[id].nt[i],mi+1);
		my[a[id].nt[i]]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i+1].t1;
	}
	for(int i=0;i<n;i++){
		int ls;
		cin>>ls;
		int x[2],y[2];
		cin>>x[1]>>y[1];
		for(int j=2;j<ls;j++){
			sz=y[1]*2;
			cin>>x[2]>>y[2];
			a[x[1]].nt[a[x[1]].nb]=x[2];
			a[x[2]].nt[a[x[2]].nb]=x[1];
			a[x[2]].nb++;
			a[x[1]].nb++;
			x[1]=x[2];
			y[1]=y[2];
		}
		sz=y[1]*2;
		cin>>x[2]>>y[2];
		a[x[1]].nt[a[x[1]].nb]=x[2];
		a[x[2]].nt[a[x[2]].nb]=x[1];
		a[x[2]].nb++;
		a[x[1]].nb++;
		x[1]=x[2];
		y[1]=y[2];
	}
	for(int i=0;i<q;i++){
		minn=1e18;
		int x, y;
		cin>>x>>y;
		for(int j=0;j<=m+1;j++)my[j]=0;
		my[x]=1;
		dfs(y,x,0);
		cout<<minn*sz+a[x].t1+a[y].t1<<endl;
	}
	return 0;
}