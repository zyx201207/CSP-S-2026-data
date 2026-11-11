#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,M=5e5+10;
int c,n,m,d,q,w[M],t[N][100],a[N][100],k[N],dis[1010][1010],vis[1010],diss[1010],st,ed;
vector <pair <int,int> > ve[M];
vector <int> mp[N],edge[N],id[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	if(c<=11){
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(int kk=j+1;kk<=k[i];kk++) ve[a[i][j]].push_back({a[i][kk],t[i][j]+t[i][kk]}),ve[a[i][kk]].push_back({a[i][j],t[i][j]+t[i][kk]});
			}
		}
		for(int st=1;st<=m;st++){
			for(int i=1;i<=m;i++) vis[i]=0,diss[i]=9e18;
			priority_queue <pair <int,int> > pq;
			pq.push({0,st});
			diss[st]=0;
			while(!pq.empty()){
				pair <int,int> top=pq.top();
				pq.pop();
				int u=top.second;
				if(vis[u]||diss[u]!=-top.first) continue;
				vis[u]=1;
				for(pair <int,int> st:ve[u]){
					int v=st.first,w=st.second;
					if(diss[v]>diss[u]+w){
						diss[v]=diss[u]+w;
						pq.push({-diss[v],v});
					}
				}
			}
			for(int i=1;i<=m;i++) dis[st][i]=diss[i]; 
		}
		while(q--){
			cin>>st>>ed;
			cout<<dis[st][ed]+w[st]+w[ed]<<"\n";
		}
	}else if(c>=12&&c<=19){
		cin>>n>>m>>d>>q;
		int T=0;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++) cin>>a[i][j]>>T,mp[i].push_back(a[i][j]),id[a[i][j]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool f=0;
				for(int k:mp[i]){
					if(f) break;
					int l=0,r=mp[j].size()-1,ans=0;
					while(l<=r){
						int mid=(l+r)>>1;
						if(mp[j][mid]>=k) r=mid-1,ans=mid;
						else l=mid+1;
					}
					if(mp[j][ans]==k){
						f=1;
						edge[i].push_back(j);
						edge[j].push_back(i);
					}
				}
			}
		}
		for(int st=1;st<=n;st++){
			queue <int> q;
			for(int i=1;i<=n;i++) vis[i]=0,diss[i]=0;
			q.push(st);
			vis[st]=1;
			while(!q.empty()){
				int h=q.front();
				q.pop();
				for(int v:edge[h]){
					if(!vis[v]){
						vis[v]=1;
						diss[v]=diss[h]+1;
						q.push(v);
					}
				}
			}
			for(int i=1;i<=n;i++) dis[st][i]=diss[i];
		}
		while(q--){
			cin>>st>>ed;
			int mn=1e18;
			for(int u:id[st]){
				for(int v:id[ed]) mn=min(mn,dis[u][v]);
			}
			cout<<w[st]+w[ed]+2*T*(mn+1)<<"\n";
		}
	}
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

0 2 5 10 2
1 1 1 1 1
3 1 1 2 1 3 1
3 2 1 4 1 5 1
3 4
1 5
60pts
*/
