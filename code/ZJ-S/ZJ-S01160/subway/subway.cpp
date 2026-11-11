#include<bits/stdc++.h>
using namespace std;
const long long inf=0x7fffffff;
int c,n,m,d,q;//c=测试点编号	n=地铁线路数	m=地铁站数	d=单站最大线路数	q=出行计划数
int w[100002];
int i,j,ii,jj;
int k[505];//线路经过的地铁站数
int a[505][505],t[505][505];
//a[i][j]=第 i 条线路经过地铁站编号
//t[i][j]=该地铁站的站厅走到站台需要的时间
int change[505];
int sum=0;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > sub;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>w[i];
	}
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			change[a[i][j]]++;
		}
	}
	int x,y;
	for(ii=1;ii<=q;ii++){
		sum=0;
		cin>>x>>y;
		for(jj=1;jj<=n;jj++){
			if(change[n]){
				sub.push_back(make_pair<t[change[[n]][],n>);
			}
			//不会做了，是要用树吗？
			//bailan 
		}
		
		
		cout<<		+w[x]+w[y];
	}
	
	
	return 0;
}
