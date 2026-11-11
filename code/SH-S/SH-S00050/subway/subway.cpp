#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500050];//从每个地铁站的地铁口走到站厅需要的时间
ll c,n,m,d,q;
//n为地铁线路数量
//m为地铁站数量
//d为每个地铁站最多被几条线路经过
//q为出行计划数量
//c为测试点编号
struct Line{
	//经过的站数
	ll k; 
	//经过了哪些站
	ll a[500050];
	//从该地铁站的站厅走到本线路的站台需要的时间
	ll t[500050];
}line[550];
struct Problem{
	//起点
	ll x;
	//终点
	ll y; 
}pb[10050];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//输入 
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>line[i].k;
		for(ll j=1;j<=line[i].k;j++){
			cin>>line[i].a[j];
			cin>>line[i].t[j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>pb[i].x;
		cin>>pb[i].y;
	}
	
	
	// 计算
	ll sum;
	for(ll i=1;i<=q;i++){
		sum+=w[pb[i].x];//地铁口到站厅 
		sum+=w[pb[i].y]; //站厅到地铁口 
	}
	
	
	return 0;
} 
