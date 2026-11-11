#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int inf=1e9;

int n;
long long d;
long long a[N];
int dis[305][305];
int f[305][305];
int maxx[305];

int main(){
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int T,c;
	cin>>c>>T;
	
	while(T--){
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dis[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dis[i][j]++;
					dis[j][i]++;
					maxx[i]=j;
				}
				else{
					break;
				}
			}
		}		
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int l=i,cnt=0;
				while(l<j&&cnt<=j-i){
					l=maxx[l];
					cnt++;
				}
				if(l<j){
					f[i][j]=-1;
				}
				else{
					f[i][j]=cnt;
				}
			}
		}
		
		for(int k=n;k>=1;k--){
			for(int i=1;i<=k-1;i++){
				if(dis[i][k]==0||f[i][k]==-1||dis[i][k]>2)continue;
				for(int j=k+1;j<=n;j++){
					if(dis[k][j]==0||f[k][j]==-1||dis[i][k]>2)continue;
					if(a[j]-a[i]<=d)continue;
					if(f[i][k]+f[k][j]!=f[i][j])continue;
					dis[i][j]+=dis[i][k]*dis[k][j];
				}
			}
		} 
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			//	cout<<f[i][j]<<" ";
				if(dis[i][j]==2){
					ans++;
				}
			}
			//cout<<"\n";
		}
		
		cout<<ans<<"\n";
	}
	
} 
/*
似乎真是数据结构？
似乎线段树优化DP

15:35

Ok一等稳完了，直接乱搞

算了正常做，看看能不能冲300pts
 
考虑什么样的岛屿对才是双径岛屿对
两条路是

x1->x2->x3……xm
y1->y2->y3……ym

且有且仅有一段 p 使得 xp!=yp

所以显然
不在这段中的点有性质 
 
设 xi->xi+1中xi+1为xi最远能到达的点 且两个点之间没有其他点可达 xi+1

在这段的点有性质 

设 xl>yl

则有 x{i+1}-yi>d(这里是距离)，不然会使得不止两条最短路径 

且 x{i}>y{i}(这里是下标）这个与上方等价

这 n<=2e6 是什么鬼 ，单log 求这个吗，这线段树咋写啊

15：50
计数题神了，不太会，没啥思路，看T4去了 

16：13 滚回来打 T3爆搜了 

16:20 似乎发现了一个不错的部分分做法，但怎么又是你，floyd!

就是每个点统计到其他点的方案数，显然floyd可做 

16:30 饼干-1
 
16:48 Ok，T3打了一个24分做法，似乎可以数据点分治？ 
不想做题了（？），不知道干啥了，再做个 T4 暴力吧，感觉其他的挺难做的
我要玩原神！

17:47 复查T3

这个小数据无疑是高强度的，但我还是再看眼。

加了个剪枝，试着跑一下。 

没问题，T4就不用看了，结论也检查不出。 
  */
