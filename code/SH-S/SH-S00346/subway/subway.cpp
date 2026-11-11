#include<bits/stdc++.h> 
#define N 503
#define M 500003
#define Q 100003
using namespace std;
typedef long long ll;
struct info{
	int cur,line;
	ll nowT;
};
int c,n,m,d,q;
int w[M],k[N];// k=a.length();
vector<pair<int,int> > a[N];
map<int,int> conn[M];// stopId, line, stop of l
//void init(){
//	for(int i=1;i<=n;i++)
//		a[i].clear();
//	for(int i=1;i<=m;i++)
//		conn[i].clear();
//}
void input(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int A,t;
		scanf("%d",&k[i]);
		a[i].push_back(make_pair(0,0));
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&A,&t);
			a[i].push_back(make_pair(A,t));
			conn[A][i]=j;
		}
//		for(int j=1;j<=k[i];j++)
//			printf("%d-%d ",a[i][j].first,a[i][j].second);
//		printf("\n");
	}
//	for(int i=1;i<=m;i++)
//		for(int j=1;j<=n;j++)
//			if(conn[i][j]!=0)printf("Stop %d is %dth stop of %d line\n",i,conn[i][j],j);
//	for(int i=1;i<=m;i++)
//		a[0].push_back(0);
}
bool vst[N][M];
ll bfs(int st,int ed){
	ll ans=1e18;
//	printf("%d %d\n",st,ed);
	for(int L=1;L<=n;L++)
		if(conn[st][L]!=0){
			queue<info> qq;
			info start;
			start.cur=st; start.line=L; start.nowT=(ll)a[L][conn[st][L]].second;
			qq.push(start);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					vst[i][j]=0;
//			printf("Entering Line %d\n",L);
			while(!qq.empty()){
				info now=qq.front(); qq.pop();
				int cur=now.cur,line=now.line; ll nowT=now.nowT;
//				printf("Stop %d Line %d nowT %d\n",cur,line,nowT);
				vst[line][cur]=1;
				// the end
				if(cur==ed){
//					printf("Reached End: Line%d Stop%d nowT %lld\n",cur,line,nowT);
					ll ret=nowT+a[line][conn[cur][line]].second;
					ans=min(ans,ret);
//					printf("updAns: %lld\n",ans);
					continue;
				}
				// no line change
				if(cur!=0){
					// 
//					printf("%d\n",vst[line][a[line][conn[cur][line]+1].first]);
					if(conn[cur][line]!=k[line]&&vst[line][a[line][conn[cur][line]+1].first]==0){
//						printf("case1\n");
						info New;
						New.cur=a[line][conn[cur][line]+1].first;
						New.line=line;
						New.nowT=nowT;
						qq.push(New);
						vst[line][New.cur]=1;
//						printf("Next Stop: Line%d Stop%d Same Line\n",line,New.cur);
					}
					// 
//					printf("%d\n",vst[line][a[line][conn[cur][line]-1].first]);
					if(conn[cur][line]!=1&&vst[line][a[line][conn[cur][line]-1].first]==0){
//						printf("case2\n");
						info New;
						New.cur=a[line][conn[cur][line]-1].first;
						New.line=line;
						New.nowT=nowT;
						qq.push(New);
						vst[line][New.cur]=1;
//						printf("Next Stop: Line%d Stop%d Same Line\n",line,New.cur);
					}
				}
				// change lines
				for(int l=1;l<=n;l++){
//					printf("Testing line %d\n",l);
					if(l!=line&&conn[cur][l]!=0&&vst[l][cur]==0){
//						printf("Line changed successfully from Line %d to line %d!\n",line,l);
						info New;
						New.cur=cur;
						New.line=l;
						New.nowT=nowT+a[line][conn[cur][line]].second+a[l][conn[cur][l]].second;
//						printf("New Line %d Extra Time: %d+%d\n",l,a[line][conn[cur][line]].second,a[l][conn[cur][l]].second);
//						printf("a_%d,%d = %d,a_%d,%d = %d\n",line,cur,a[line][conn[cur][line]].second,l,cur,a[l][conn[cur][l]].second);
						qq.push(New);
						vst[l][cur]=1;
//						printf("Next Stop: Line%d Stop%d nowT %lld Changed Line\n",l,cur,New.nowT);
					}
				}
		}
	}
	return ans;
}
void solvebf(){
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",bfs(x,y)+(ll)(w[x]+w[y]));
	}
}
int main(){// (31)8=(25)10
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
//	solve();
	solvebf();
	return 0;
}
