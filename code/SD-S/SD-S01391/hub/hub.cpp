#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
int fa[53],dis[53];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void ckmin(int &a,int b) {
	a=a<b?a:b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		int n,k,ans=1e5;
		cin>>n>>k;
		int N=1<<n;
		vector<pair<int,int> >e;
		for(int i=1,u,v; i<n; i++)cin>>u>>v,e.push_back({u,v});
		for(int p=0; p<N; p++) {
			if(__builtin_popcount(p)!=k)continue;
			for(int i=1; i<=n; i++)fa[i]=i;
			for(auto i:e)
				if((p&(1<<(i.first-1)))&&(p&(1<<(i.second-1))))
					fa[get(i.first)]=get(i.second);
			int cnt=0,nw=0;
			for(int i=1; i<=n; i++)if((p&(1<<(i-1)))&&fa[i]==i)cnt++;
			if(cnt!=2)continue;
			memset(dis,0x3f,sizeof(dis));
			for(int i=1; i<=n; i++)
				if(p&(1<<(i-1)))dis[i]=0;
			for(int i=1; i<=n; i++) {
				for(auto s:e) {
					ckmin(dis[s.first],dis[s.second]+1);
					ckmin(dis[s.second],dis[s.first]+1);
				}
			}
			for(int i=1; i<=n; i++)nw=dis[i]>nw?dis[i]:nw;
//			cout<<p<<' '<<nw<<endl;
			ans=nw<ans?nw:ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
