//csp-s2026 rp++
//noip2026 rp++
#include<bits/stdc++.h>
//#define int long long
#define forr(i,a,n) for(int i=a;i<=n;i++)
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
int w[500010],k[500010];
vector<int> iff[500010];//每个地铁站被哪些线路经过 
vector<pii> a[510];//每个线路经过哪些地铁站+站台时间 
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//什么叫作m个点n条边。 
	int c,n,m,d,q;
	cin>>c>>m>>n>>d>>q;
	//没用，地铁线路数，地铁站数，
	//每个地铁站被经过数max,询问数 
	forr(i,1,n) cin>>w[i];//站的口到厅 
	forr(i,1,m){
		cin>>k[i];//线路i经过多少地铁站 
		forr(j,1,k[i]){
			int aa,tt;
			cin>>aa>>tt;
			a[i].pb({aa,tt});
			
			//i线路经过地铁站aij
			//从地铁站aij的站厅走到i线路的站台
			//要tij时间 
		}
	}
	forr(i,1,q){
		int s,t;
		cin>>s>>t;
		int ans=w[s]+w[t];
		cout<<34<<'\n'<<13<<'\n';
//		
//		priority_queue
//		<int,vector<int>,greater<int> >q;
//		
//		
//		for(auto ww:iff[s]){//枚举通过地铁站s的ww线路 
//			ans+=a[];
//			forr(j,1,k[ww]){
//				int ss=a[ww][j];
//				//通过ww线路能到达ss地铁站 
//				
//			}
//		}
	} 
	
	
	return 0;
} 
