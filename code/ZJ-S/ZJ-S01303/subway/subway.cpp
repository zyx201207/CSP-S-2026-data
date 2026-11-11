//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//const int nmax = 1159764;
//
//int c,n,m,d,q;
//ll w[nmax];
//int k[505];
//vector<int>a[505];
//vector<ll>t[505];
//
//vector<pair<int,ll>>g[nmax];
//int ans[nmax];
//struct queries{
//	int u,v;int id;
//}Qs[nmax];
//
//bool cmp(queries a,queries b){
//	return a.u<b.u;
//}
//
//ll dift[nmax];
//bool vis[nmax];
//inline void DIJ(int s){
//	memset(dift,0x3f,sizeof dift);
//	dift[s]=0;
//	memset(vis,0,sizeof vis);
//#define pll pair<ll,ll>
//	priority_queue<pll,vector<pll>,greater<pll > >pq;
//#undef pll
// pq.push({0,s});
// while(!pq.empty()){
// 	int u=pq.top().second;
// 	pq.pop();
// 	if(vis[u])continue;
// 	vis[u]=1;
// 	for(auto i : g[u]){
// 		int v;ll w;
// 		v=i.first;
// 		w=i.second;
// 		if(dift[v]>dift[u]+w)
// 			dift[v]=dift[u]+w,
// 			pq.push({dift[v],v});
//		}
//	}
//	return;
//}
//
///*
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//*/
//
//int tot;
//int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	
//	//DIJ(1);return 0;
//	
// cin>>c>>n>>m>>d>>q;
// for(int i=1;i<=m;i++){
// 	cin>>w[i];
//	};
//	tot=m;
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		a[i].push_back(0);
//		t[i].push_back(0);
//		++tot;
//		for(int j=1;j<=k[i];j++){
//			int aij,tij;cin>>aij>>tij;
//			a[i].push_back(aij);
//			t[i].push_back(tij);
//		 g[tot].push_back({aij,tij});
//		 g[aij].push_back({tot,tij});
//		}
//	}
//	
//	// d<=20
//	// every station's du <= 20
//	
//	// g is the graph
//	for(int i=1;i<=q;i++){
//		int x,y;cin>>x>>y;
//		Qs[i]={min(x,y),max(x,y),i};
//	}
//	sort(Qs+1,Qs+1+q,cmp);
//	
//	int lst=0;
//	for(int i=1;i<=q;i++){
//		int u,v;
//		u=Qs[i].u;
//		v=Qs[i].v;
//		int id=Qs[i].id;
//		
//		if(u==lst){
//			ans[id]=dift[v]+w[u]+w[v];
//			lst=u;
//			continue;
//		};
//		
//		DIJ(u);
//		ans[id]=dift[v]+w[u]+w[v];
//		lst=u;
//	}
//	
//	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
//	
// return 0;
//};

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int nmax = 1159764;

inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-f;ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48,ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x==0)putchar('0');
	static short stk[80],top=0;
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]|48);
}

int c,n,m,d,q;
ll w[nmax];
int k[505];

vector<pair<int,ll>>g[nmax];
ll ans[nmax];
struct queries{
	int u,v,id;
}Qs[nmax];

bool cmp(queries a,queries b){
	return a.u<b.u;
}

ll dift[nmax];
bool vis[nmax];
int tot;


/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
	
	//DIJ(1);return 0;
	
 //cin>>c>>n>>m>>d>>q;
 c=read();n=read(),m=read();
 d=read();q=read();
 for(int i=1;i<=m;i++){
// 	cin>>w[i];
  w[i]=read();
	};
	tot=m;
	for(int i=1;i<=n;i++){
	//	cin>>k[i];
	 k[i]=read();
		++tot;
		for(int j=1;j<=k[i];j++){
			int aij,tij;
			aij=read(),tij=read();//cin>>aij>>tij;
		 g[tot].push_back({aij,tij});
		 g[aij].push_back({tot,tij});
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;//cin>>x>>y;
		x=read(),y=read();
		Qs[i]={min(x,y),max(x,y),i};
	}
	sort(Qs+1,Qs+1+q,cmp);
	
	int lst=0;
	for(int i=1;i<=q;i++){
		int u,v;
		u=Qs[i].u;
		v=Qs[i].v;
		int id=Qs[i].id;
		
		if(u==lst){
			ans[id]=dift[v]+w[u]+w[v];
			lst=u;
			continue;
		};
		
	int s=u;
 for(int i=0;i<=tot;i++)dift[i]=1e18,vis[i]=0;
	dift[s]=0;
#define pll pair<ll,ll>
	priority_queue<pll,vector<pll>,greater<pll > >pq;
#undef pll
 pq.push({0,s});
 while(!pq.empty()){
 	int u=pq.top().second;
 	pq.pop();
 	if(vis[u])continue;
 	vis[u]=1;
 	for(auto i : g[u]){
 		int v;ll w;
 		v=i.first;
 		w=i.second;
 		if(dift[v]>dift[u]+w)
 			dift[v]=dift[u]+w,
 			pq.push({dift[v],v});
		}
	}

		ans[id]=dift[v]+w[u]+w[v];
		lst=u;
	}
	
	for(int i=1;i<=q;i++)//cout<<ans[i]<<"\n";
	 write(ans[i]),putchar('\n');
	// fylfly is GOOD
	// ckr_taste_tasty is GOOD
 // www_ac is VERY GOOD
 // LvYiGe8888 is VERY GOOD
 // for me, rp++
 // luogu user 1159764
 return 0;
};