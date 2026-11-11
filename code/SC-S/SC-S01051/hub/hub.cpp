#include<iostream>
#include<vector>
using namespace std;
#define N 1000002
int c,t,n,k,i,cntf,cntj,ans,dis[N],que[N],ql,qr,q2[N],q2l,q2r,u;
bool f[N],vis[N],v2[N],no;
vector<int>nxt[N];
inline void solve(){
	cin>>n>>k;ans=11451411;
	for(i=1;i<=n;++i)nxt[i].clear();
	for(i=1;i<n;++i)cin>>cntf>>cntj,
	nxt[cntf].push_back(cntj),
	nxt[cntj].push_back(cntf),
	f[i]=0;cntf=0;
	while(true){
		i=1;
		while(i<=n&&f[i])--cntf,f[i]=false,++i;
		++cntf;
		if(i==n+1)break;f[i]=true;
		if(cntf!=k)continue;
		ql=0;qr=0;cntj=0;
		for(i=1;i<=n;++i)vis[i]=v2[i]=dis[i]=0;
		for(i=1;i<=n;++i){
			if(f[i]){
				que[qr++]=i,vis[i]=true;
				if(!v2[i]){
					++cntj;
					if(cntj>2)break;
					q2l=0;q2r=1;q2[0]=i;v2[i]=true;
					while(q2l<q2r){
						u=q2[q2l++];
						for(int v:nxt[u]){
							if(f[v]&&!v2[v])q2[q2r++]=v,v2[v]=true;
						}
					}
				}
				
			}
		}if(cntj>2)continue;no=false;
		while(ql<qr){
			i=que[ql++];
			for(int v:nxt[i]){
				if(!vis[v]){
					que[qr++]=v,vis[v]=true,dis[v]=dis[i]+1;
					if(dis[v]>=ans){
						no=true;
						break;
					}
				}
			}if(no)break;
		}if(no)continue;
		ans=dis[i];
	}cout<<ans<<'\n';
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;while(t--)solve();
	return 0;
}