#include<bits/stdc++.h>
using namespace std;

const long long MAXN=5e5;
long long c,n,m,d,q;
long long grh[505][505];//邻接表存图
struct Node{//stat不能当名称？？？
	long long w,cnt;//到站厅时间 连通线路数
	long long nxt[21][2];//0线路 1时间
}sta[MAXN+5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&sta[i].w);
	}for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long a,t;
			scanf("%lld%lld",&a,&t);//到哪个站台 用时
			sta[a].cnt++;
			sta[a].nxt[sta[a].cnt][0]=i;
			sta[a].nxt[sta[a].cnt][1]=t;
//			printf("%d %d %d\n",a,sta[a].nxt[sta[a].cnt][0],sta[a].nxt[sta[a].cnt][1]);
		}
	}
//	for(long long i=1;i<=m;i++){
//		for(long long j=1;j<=sta[i].cnt;j++){
//			printf("%d %d %d\n",i,sta[i].nxt[j][0],sta[i].nxt[j][1]);
//		}printf("ed\n");
//	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			grh[i][j]=LLONG_MAX;
		}
		grh[i][i]=0;
	}
	long long nm,val;
	for(long long o=1;o<=m;o++){//建图
		nm=sta[o].cnt;
//		printf("%d %d\n",o,nm);
		for(long long i=1;i<=nm;i++){
			for(long long j=i+1;j<=nm;j++){
				val=sta[o].nxt[i][1]+sta[o].nxt[j][1];
//				printf("va:%d\n",val);
				grh[sta[o].nxt[i][0]][sta[o].nxt[j][0]]=min(val,grh[sta[o].nxt[i][0]][sta[o].nxt[j][0]]);
				grh[sta[o].nxt[j][0]][sta[o].nxt[i][0]]=min(val,grh[sta[o].nxt[i][0]][sta[o].nxt[j][0]]);
			}
		}
	}
//	for(long long i=1;i<=n;i++){
//		for(long long j=1;j<=n;j++){
//			printf("%d ",grh[i][j]);
//		}printf("\n");
//	}
	for(long long i=1;i<=n;i++){//跑最短路
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				if(grh[k][j]!=LLONG_MAX&&grh[i][k]!=LLONG_MAX){
					grh[i][j]=min(grh[i][j],grh[i][k]+grh[k][j]);
				}
			}
		}
	}
	
	long long x,y,ans,cur;
	for(long long pp=1;pp<=q;pp++){
		scanf("%lld%lld",&x,&y);
		ans=LLONG_MAX;
		
		for(long long i=1;i<=sta[x].cnt;i++){//每个起点到每个终点 注意两条线最短正好经过原点特判
			for(long long j=1;j<=sta[y].cnt;j++){
//				printf("%d %d\n",sta[x].nxt[i][0],sta[y].nxt[j][0]);
				cur=sta[x].w+sta[y].w;
				cur+=sta[x].nxt[i][1]+sta[y].nxt[j][1];
				//如果连接同一个线路
				cur+=grh[sta[x].nxt[i][0]][sta[y].nxt[j][0]];
				//
//				printf("%d\n",cur);
				//一般情况
				ans=min(ans,cur);
			}
		}//sta[x].w+sta[y].w+grh[x][y]
		printf("%lld\n",ans);
	}
	//
//	printf("%d\n",ans);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/