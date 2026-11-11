#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
int w[N];//表示从每个地铁站的地铁口走到站厅需要的时间
int k[N];//表示第i条线路经过的地铁站数
int a[510][N];//表示第i条线路经过的第j个地铁站
int t[510][N];//表示从该地铁站的站厅走到第i条线路的站台需要的时间
int s[30],e[30];
long long min_time(int x,int y){
	int l1=0,l2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				s[++l1]=i;
			}
			if(a[i][j]==y){
				e[++l2]=i;
			}
		}
	}
	bool p=0;
	int lx=0;
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s[i]==e[j]){
				p=1;
				lx=s[i];
				break;
			}
		} 
	} 
	int sid=0,eid=0;
	if(p){
		for(int i=1;i<=n;i++){
			if(a[lx][i]==x){
				sid=i;
			}
			if(a[lx][i]==y){
				eid=i;
			}
			if(eid&&sid)break;
		}
	}
	long long time=0;
	time+=w[sid]+w[eid];
	for(int i=min(sid,eid);i<=max(sid,eid);i++){
		time+=t[lx][i];
	}
	return time;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<min_time(x,y)<<'\n';
	}
	return 0;
} 