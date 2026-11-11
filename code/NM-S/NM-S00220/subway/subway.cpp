#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//c, n, m, d, q，分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[500005];// 从每个地铁站的地铁口走到站厅需要的时间
int ans;//答案 
struct dt{
	int much;
	int sta[500005];
	int time[500005];
};dt way[505];//路线结构体 
struct pl{
	int start,end;
};pl plan[100005];//计划结构体 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>way[i].much;
		for(int j=1;j<=way[i].much;j++){
			cin>>way[j].sta[j]>>way[j].time[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan[i].start>>plan[i].end;
		ans=w[plan[i].start]+w[plan[i].end]+way[0].time[plan[i].start]+way[0].time[plan[i].end];
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
