#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=2e4+10,M2=5e5+10;
long long c,n,m,d,q,k,t[2*M2],h[2*M2],u,v,w,dis[N][2*M],dis2[5][2*M2],a[2*M2],cnt,vis[2*M2],ans,x,y;
struct node{
	long long v,w,pre;
}b[2*M2];
void add(){
	b[++cnt].v=v;
	b[cnt].w=w;
	b[cnt].pre=h[u];
	h[u]=cnt;
}
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> p;
int main(){
	//保底52，测评机跑得快有68 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>w;
			u=a[j],v=m+i;
			add();
			swap(u,v);
			add();
		}
		/*for(int j=1;j<k;j++){
			u=a[j],v=a[j+1],w=0;
			add();
		}*/
	}
	
	if(n<=2){
		memset(dis2,0x3f,sizeof(dis2));
		for(k=1;k<=n;k++){
			dis2[k][k+m]=0;
			p.push({0,k+m});
			memset(vis,0,sizeof(vis));
			
			while(!p.empty()){
				u=p.top().second;
				p.pop();
				if(vis[u])continue;
				vis[u]=1;
				
				for(int i=h[u];i;i=b[i].pre){
					v=b[i].v,w=b[i].w;
					if(dis2[k][u]+w<dis2[k][v]){
						dis2[k][v]=dis2[k][u]+w;
						p.push({dis2[k][v],v});
					}
				}
			}
		}
		while(q--){
			cin>>x>>y;
			ans=9e18;
			for(int i=1;i<=n;i++){
				ans=min(ans,dis2[i][x]+dis2[i][y]);
			}
			//cout<<ans<<"\n";
			ans+=t[x]+t[y];
			cout<<ans<<'\n';
		}
		return 0; 
	}
	memset(dis,0x3f,sizeof(dis));
	for(k=1;k<=n;k++){
		dis[k][k+m]=0;
		p.push({0,k+m});
		memset(vis,0,sizeof(vis));
		
		while(!p.empty()){
			u=p.top().second;
			p.pop();
			if(vis[u])continue;
			vis[u]=1;
			
			for(int i=h[u];i;i=b[i].pre){
				v=b[i].v,w=b[i].w;
				if(dis[k][u]+w<dis[k][v]){
					dis[k][v]=dis[k][u]+w;
					p.push({dis[k][v],v});
				}
			}
		}
	}
	
	while(q--){
		cin>>x>>y;
		ans=9e18;
		for(int i=1;i<=n;i++){
			ans=min(ans,dis[i][x]+dis[i][y]);
		}
		//cout<<ans<<"\n";
		ans+=t[x]+t[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
