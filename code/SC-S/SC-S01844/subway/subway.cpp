#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	//测试点编号、线路数、站数、每个站最多被几条线路经过，出行计划数
	
	vector<int> w(m+1);//每个站的站口走到站厅需要的时间
	for(int i=1;i<=m;i++) cin>>w[i];
	
	vector<int> k(n+1);//第i条线路经过的地铁站数量 
	vector<vector<bool> > a(n+1,vector<bool>(m+1));//第 i 条线路是否经过第j 个地铁站
	vector<vector<int> > t(n+1,vector<int>(n+1));//该站的站厅走到第i条线路的站台需要的时间
	for(int i=1;i<=n;i++){
		cin>>k[i];int A,T;
		for(int j=1;j<=k[i];j++)
			cin>>A>>T,a[i][A]=1,t[i][A]=T;
	}
	while(q--){
		int x,y;cin>>x>>y;//第r 个出行计划的起点和终点所在的地铁站编号
		int ans=w[x]+w[y];
		int s1=1e10,s2=1e10,s3=1e10,s4=1e10;//1   12   2    21
		int mi=1e10;
		for(int i=1;i<=m;i++)
			if(a[1][i]==1&&a[2][i]==1)
				mi=min(mi,t[1][i]+t[2][i]);
		if(a[1][x]==1){
			if(a[1][y]==1) s1=t[1][x]+t[1][y];
			else s2=t[1][x]+mi+t[2][y];
		} else{
			if(a[2][y]==1) s3=t[2][x]+t[2][y];
			else s4=t[2][x]+mi+t[1][y];
		}
		cout<<ans+min(s1,min(s2,min(s3,s4)))<<"\n";
	}
	return 0;
}