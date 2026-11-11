#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const long long inf=1e18;

int c,n,m,d,q;
long long w[N];

struct tation{
	int p;
	long long t;
};

vector<tation>b[N];

vector<int>a[505];


long long dis[505][505];

long long minn(long long x,long long y){
	return x>y?y:x;
} 

int main(){
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++){
			
			int p,t;
			cin>>p>>t;
			
			b[p].push_back({i,t});
			a[i].push_back(p);
		}
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			if(i==j){
				dis[i][j]=0;
			}
			
			else{
				dis[i][j]=inf;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		
		for(int now:a[i]){
			
			long long k=0;
			for(auto v:b[now]){
				
				if(v.p==i){
					
					k=v.t;
					break;
				}
			}
			
			for(auto v:b[now]){
				
				if(v.p==i){
					
					continue;
				}
				dis[i][v.p]=min(dis[i][v.p],k+v.t);
				dis[v.p][i]=dis[i][v.p];
			}
		}
	} 
	
	for(int k=n;k>=1;k--){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		} 
	} 
	
	for(int i=1;i<=q;i++){
		
		int x,y;
		cin>>x>>y;
		
		long long ans=inf;
		
		for(auto v:b[x]){
			
			for(auto u:b[y]){
				ans=min(dis[v.p][u.p]+v.t+u.t,ans);
			}
		}
		
		cout<<w[x]+w[y]+ans<<"\n";
	}
} 
/*
出入站显然无用
考虑换一种方式连边 
500？难道folyd?
确实应该是folyd
刚好全源最短路。

所以考虑连边

如果在同一条线路？不能将整条线路压缩，可能有转线

所以前一个和后一个连 0 的边

若不在同一条线路内则连转线的权值

跑最短路即可

时间复杂度 O(n^3);完全可过

15：00

开始实现，预计1h 

发现转线很难处理权值。

可以处理每个点到不同线的最小值吗？
 
发现看错了500是线路数……

但是d<=20 

完全可以处理两条线距离权值 

先处理直接相连 O(sum{k}*b) 显然可过

接下来处理间接，复杂度 O(n^3). 

成功通过所有大样例 200pts! 

17:35 复查 T2

大样例还算有点良心，不过咋也不是满的啊。 

还是算下复杂度

n^3 的话是 1.25e8,自己写个 minn 吧，看下要不要开祖宗 。

显然要，检查一下该开的都开了没 

为了保险，w和 t都开了。据说ccf 大常熟 5e8随便跑。

感觉有点悬啊，本地跑了 0.4s，还不是满数据 

不是悬在哪 ，满数据就加点常数，本地这么快那不是随便跑. 

不是这个16~19的咋跑这么慢，哦，是满数据啊，只是有个答案的性质，那没事了。 
*/
 
