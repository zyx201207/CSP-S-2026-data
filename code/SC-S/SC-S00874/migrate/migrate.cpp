#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=1e18;
int c,T,n,d,a[N],nxt[N],pre[N],dpr[N],dpl[N];
int dis[5005],cnt[5005];
vector<int>g[5005];
//bool ok1[N],ok2[N];
struct node{
	int x,y;
	bool operator <(const node &other)const{
		return y>other.y;
	}
};
void dijkstra(int st){
	for(int i=1;i<=n;i++){
		dis[i]=INF,cnt[i]=0;
	}
	priority_queue<node>q;
	q.push({st,0});
	dis[st]=0;
	cnt[st]=1;
	while(!q.empty()){
		int u=q.top().x,d=q.top().y;q.pop();
		if(dis[u]!=d)continue;
		for(int v:g[u]){
			int nd=d+1;
			if(nd<dis[v]){
				dis[v]=nd;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}
			else if(nd==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	} 
}
signed main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nxt[i]=pre[i]=0;
			dpr[i]=dpl[i]=1;
		}
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				g[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
//					if(i==j)continue;
					if(abs(a[i]-a[j])<=d){
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				dijkstra(i);
				for(int j=1;j<=n;j++){
					if(cnt[j]==2){
						ans++;
//						cout<<i<<" "<<j<<'\n';
					}
				}
			}
			cout<<ans/2<<'\n';
			continue;
		}
//		int cur=2;
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]==d){
				nxt[i]=i+1;
				pre[i+1]=i;
			}
//			while(cur<n&&a[cur]<a[i]+d){
//				cur++;
//			}
//			if(a[cur]==a[i]+d){
//				nxt[i]=cur;
//				pre[cur]=i;
//			}
		}
		for(int i=1;i<=n;i++){
			if(pre[i]){
				dpl[i]+=dpl[pre[i]];
			}
		}
		for(int i=n;i>=1;i--){
			if(nxt[i]){
				dpr[i]+=dpr[nxt[i]];
			}
		}
		int r=1,l_to_r=1,r_to_l=1,cnt=0,ans=0;
		for(int l=1;l<=n;l++){
			bool flag=true;
			while(r<n&&(a[l]+d>=a[r]||cnt>=2)){
				flag=true;
//				cout<<l<<" "<<r<<" "<<l_to_r<<" "<<r_to_l<<" "<<cnt<<'\n';
				r++;
				while(l_to_r<r&&a[l]+d>=a[l_to_r+1]){
					l_to_r++;
				}
				while(r_to_l<n&&a[r]-d>a[r_to_l]){
					r_to_l++;
				}
				if(r_to_l==r||l_to_r==0||a[l]+d>=a[r])cnt=0;
				else cnt=min(l_to_r,r-1)-max(l+1,r_to_l)+1;
				if(cnt==2){
//					cout<<l<<" "<<r<<" "<<dpl[l]<<" "<<dpr[r]<<" "<<l_to_r<<" "<<r_to_l<<'\n';
					flag=false;
					ans+=dpl[l]*dpr[r];
				}
			}
			while(l_to_r<r&&a[l]+d>=a[l_to_r+1]){
				l_to_r++;
			}
			while(r_to_l<n&&a[r]-d>a[r_to_l]){
				r_to_l++;
			}
			if(r_to_l==r||l_to_r==0||a[l]+d>=a[r])cnt=0;
			else cnt=min(l_to_r,r-1)-max(l+1,r_to_l)+1;
			if(flag&&cnt==2){
//				cout<<l<<" "<<r<<" "<<dpl[l]<<" "<<dpr[r]<<" "<<l_to_r<<" "<<r_to_l<<'\n';
				ans+=dpl[l]*dpr[r];
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 1
6 3
0 1 2 3 4 7
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/