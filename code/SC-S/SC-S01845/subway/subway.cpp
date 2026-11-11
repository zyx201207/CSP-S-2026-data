#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=502,MAXM=5e5+2;//MAXN表示最大线路，MAXM表示最大地铁站数
int c,n,m,d,q;
/*c测试点编号、n地铁线路数、m地铁站数、
d每个地铁站最多被几条线路经过，q以及出行计划数*/
int w[MAXM];//每个地铁站的地铁口走到站厅需要的时间
struct node{
	int id,w;
};
vector<node>t[MAXN];
/*t[i][j].id表第i条线路上的第j个站台属于编号为t[i][j].id的地铁站 
t[i][j].w表第i条线路上的第j个站台走到编号为t[i][j].id的地铁站的站厅所需的时间*/

//solve
ll dp[200+400+2][200+400+2];//Floyd 
int num1[MAXM],cnt1[MAXM]; 
int Num1=0;
int N1[MAXM];
//num表示每一个地铁站经过的线路数，cnt表示每一个地铁站编号偏移量.
//N表示地铁站的站台设置了多少个； 
void solve1(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=2;i<=m;i++)
		cnt1[i]=cnt1[i-1]+(num1[i-1]+1);//站台数加站厅1 
	for(int i=1;i<=n;i++){
		for(auto j:t[i]){
			N1[j.id]++;
			int x_tai=n+cnt1[j.id]+1+N1[j.id];
			int x_ting=n+cnt1[j.id]+1;
			dp[i][x_tai]=0;dp[x_tai][i]=0;
			dp[x_ting][x_tai]=j.w;dp[x_tai][x_ting]=j.w;
		}
	}
	Num1+=n;
	Num1+=m;
	//floyd
	for(int k=1;k<=Num1;k++){
		for(int i=1;i<=Num1;i++){
			for(int j=1;j<=Num1;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//in
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;//第i条线路上的站台数
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int id,w;
			scanf("%d%d",&id,&w);
			t[i].push_back({id,w});
			
			num1[id]++;
			Num1++;
			
		} 
	}
	
	if(c<=8){
		solve1();
	}
	
	//Q
	while(q--){
		int from,to;
		scanf("%d%d",&from,&to);
		if(c<=8){
			ll ans=dp[n+cnt1[from]+1][n+cnt1[to]+1]+w[from]+w[to];
			printf("%lld\n",ans);
		}
	}
}