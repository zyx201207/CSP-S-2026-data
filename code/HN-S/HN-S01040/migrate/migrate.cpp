#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000005];
int g[2000005];
int dis[2000005];
int ans;
int minn[2000005];
struct note{
	int x,y;
	bool operator <(const note &b)const{
		return b.y<y;
	}
};
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<note>q;
	q.push({s,0});
	while(!q.empty()){
		int x=q.top().x,y=q.top().y;
		q.pop();
		for(int i=x;i<=g[x];i++){
			int yy=i;
			if(dis[x]+1<dis[yy]){
				dis[yy]=dis[x]+1;
				minn[yy]=1;
				q.push({yy,dis[yy]});
			}
			else if(dis[x]+1==dis[yy]){
				dis[yy]=dis[x]+1;
				minn[yy]++;
				q.push({yy,dis[yy]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			minn[i]=1;
			int l=i,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[i]<=d)l=mid+1;
				else r=mid-1;
			}
			g[i]=r;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++){
				//cout<<minn[j]<<endl;
				if(minn[j]==2)ans++;
				minn[j]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
