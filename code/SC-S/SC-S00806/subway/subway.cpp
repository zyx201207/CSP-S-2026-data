#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans1,
	oo[500002],pp[500002],map1[500002],v[502],
	w[500002],//表示从每个地铁站的地铁口走到站厅需要的时间
	k[500002],//第i条线路经过的地铁站数
	x[100002],//第r 个出行计划的起点所在的地铁站编号
	y[100002];//第r 个出行计划的终点所在的地铁站编号
struct node{
	string aa;//表示第 i 条线路经过的第j 个地铁站
	string t;//表示从该地铁站的站厅走到第i条线路的站台需要的时间
}a[502];
struct node1{
	string rr;//表示第 i 个地铁站所在的第j 条线路
}r[500002];
void dfs(int xx,int yy,int ans,int q){//xx x[i]
	if(xx==yy) {
		ans1=ans;
		return;
	}
	if(map1[xx]!=0) return; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i].aa[j]==char(xx-'0')){
				for(int z=1;z<r[a[i].aa[j]].rr.size();z++){
					for(int o=1;j<=k[r[a[i].aa[j]].rr[z]];o++){
						if(o!=j){
							map1[a[i].aa[o]]=1;
							dfs(a[i].aa[o],yy,ans+a[i].t[o],q);
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].aa='0';
		a[i].t='0';
		for(int j=1;j<=k[i];j++){
			cin>>oo[j]>>pp[j];
			a[i].aa=a[i].aa+char(oo[j]-'0');
			a[i].t=a[i].t+char(pp[j]-'0');
			r[oo[j]].rr=r[oo[j]].rr+char(i-'0');
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		memset(a,sizeof(a),0);
		dfs(x[i],y[i],0,x[i]);
		cout<<ans1<<endl;
	}
	return 0;
}