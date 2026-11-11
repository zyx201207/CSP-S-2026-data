#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,d,x[N],d_[N];
ll dis[N][3];
void dijkstra(int st)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	dis[0][0]=0;
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		pair<int,int> cur=pq.top();
		pq.pop();
		int pos=cur.second,wt=cur.first;
		for(int i=pos;i<=n&&x[i]-x[pos]<=d;++i){
			int nv=wt+1;
			if(nv<dis[i][0]){
				dis[i][2]=dis[i][1];
				dis[i][1]=dis[i][0];
				dis[i][0]=nv;
				pq.push(make_pair(nv,i));
			}
			else if(nv<dis[i][1]){
				dis[i][2]=dis[i][1];
				dis[i][1]=nv;
				pq.push(make_pair(nv,i));
			}
			else if(nv<dis[i][2]){
				dis[i][2]=nv;
				pq.push(make_pair(nv,i));
			}
		}
	}
	return;
}
ll solve(int l,int r)
{
	if(l>=r) return 0;
	ll res=0;
	for(int i=1;i<=l;++i){
		memset(dis,0x3f,sizeof(dis));
		dijkstra(i);
		for(int j=i+1;j<=r;j++){
			if(dis[j][0]==dis[j][1]&&dis[j][1]!=dis[j][2]) res++;
		}
	}
	return res;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=2;i<=n;++i) d_[i]=x[i]-x[i-1];
		
		int lt=1;
		ll ans=0;
		for(int i=2;i<=n;i++){
			if(d_[i]>d){
				ll p=solve(lt,i-1);
				ans+=p;
				lt=i; 
			}
		}
		if(lt<n) ans+=solve(lt,n);
		cout<<ans<<"\n";
	}
	return 0;
 } 
