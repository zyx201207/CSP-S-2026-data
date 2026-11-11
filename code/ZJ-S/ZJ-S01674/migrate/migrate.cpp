#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,M=2e6+100;
int n,a[M],d,dis[N],vis[N],hhr[N],f[M];
vector<int> u[N];
inline void D(int s){
	for(int i=1;i<=n;i++) dis[i]=100000000,vis[i]=hhr[i]=0;
	dis[s]=0,hhr[s]=1;
	queue< pair<int,int> > q; q.push({0,s});
	while(!q.empty()){
		int p=q.front().second; q.pop();
		if(vis[p]) continue;
		vis[p]=1;
		for(int i=0;i<(int)u[p].size();i++){
			int v=u[p][i];
			if(dis[v]>dis[p]+1){
				dis[v]=dis[p]+1,hhr[v]=hhr[p]; q.push({dis[v],v});
			}
			else if(dis[v]==dis[p]+1) hhr[v]+=hhr[p];
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n>5000){
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
			int l=i,r=n,to=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=d) to=mid,l=mid+1;
				else r=mid-1;
			}
				f[i]=to;
			}
			int c=a[2]-a[1],ans=0;
			for(int i=1;i<=n;i++){
				int to1=f[i];
				int to2=f[to1];
				int now1=(to1-i)/c;
				int now2=(to2-to1)/c;
				if(now1==now2+1) ++ans;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i],u[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) u[i].push_back(j);
				else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			D(i);
			for(int j=i+1;j<=n;j++){
				if(hhr[j]==2) ans++;
//				cout<<i<<" "<<j<<" "<<dis[j]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}	
	return 0;
}
