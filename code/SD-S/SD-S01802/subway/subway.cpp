#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
long long cnt,ans[100005];
struct way__{
	int idx;
	int station[20005];
}way[505];
struct station__way{
	long long time[505];//第j条线对应该站点的时间 
}s[20005]; //第i个站点所对应的各数值 
int c,n,m,d,q;//测试点编号；n条路线，m个站台，d最多经过线路数，q出行计划数 
int w[20005],k[505],x[100005],y[100005];//口->厅的时间w，经过站数k，站台编号a， 厅->台时间t，出发地x，目的地y
void dfs(int a,int l,long long time,int de){//当前站点，当前线路，当前用时，目的地 
	if(time>=cnt)return;
	for(int i=1;i<=k[l];i++){
		if(way[l].station[i]==a)continue;
		if(way[l].station[i]==de){
			cnt=min(cnt,time+(s[way[l].station[i]].time[l]));
			return;
		}
		for(int j=1;j<=n;j++){
			if(j==l)continue;
			if(s[way[l].station[i]].time[j]!=0){
				dfs(way[l].station[i],j,time+(s[way[l].station[i]].time[j]+s[way[l].station[i]].time[l]),de);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ans,0x3f3f3f3f,sizeof(ans));
	for(int i=1;i<=500;i++){
		way[i].idx=1;
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			long long t;
			cin>>a>>t;
			s[a].time[i]=t;
			way[i].station[way[i].idx]=a;
			way[i].idx++;
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int an=1;an<=q;an++){
		for(int i=1;i<=n;i++){
			if(s[x[an]].time[i]==0)continue;
			cnt=0x3f3f3f3f;
			dfs(x[an],i,s[x[an]].time[i],y[an]);
			ans[an]=min(ans[an],cnt+w[x[an]]+w[y[an]]);
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	return 0;
}
/*
正解我不会qwq
*/
