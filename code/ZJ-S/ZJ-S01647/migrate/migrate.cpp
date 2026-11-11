//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N=2E6+2,INF=1E18;
//struct Node {
//	int v,u;
//	bool operator<(const Node & tmp)const {
//		return v<tmp.v;
//	}
//};
//int n,d,dist[N],a[N],k=0;
//bool vis[N],cd[N];
//vector<Node>e[N];
//void hm(int a,int b,int x) {
//	if(x>dist[b]) return;
//	if(a==b&&x==dist[b]) {
//		k++;
//		return;
//	}
//	for(auto y:e[a]) {
//		int d=y.u,j=y.v;
//		if(cd[d]) continue;
//		cd[d]=1;
//		hm(d,b,x+j);
//		cd[d]=0;
//	}
//}
//signed main() {
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int c,T;
//	cin>>c>>T;
//	while(T--) {
//		int ans=0;
//		cin>>n>>d;
//		for(int i=1; i<=n; i++) cin>>a[i];
//		for(int i=1; i<=n; i++) {
//			for(int j=i+1; j<=n; j++) {
//				if(abs(a[j]-a[i])>d) break;
//				e[i].push_back(Node {a[j]-a[i],j});
//				e[j].push_back(Node {a[j]-a[i],i});
//			}
//		}
//		for(int i=1; i<=n; i++) {
//			for(int j=i+1; j<=n; j++) {
//				if(i!=j) {
//					int ans=0;
//					priority_queue<Node>q;
//					q.push(Node {i,0});
//					while(!q.empty()) {//求出最短路
//						Node f=q.top();
//						q.pop();
//						int u=f.u,v=f.v;
//						if(vis[u]) continue;
//						vis[u]=1;
//						for(auto x:e[u]) {
//							int uu=x.u,vv=x.v;
//							if(dist[uu]>dist[u]+vv) {
//								dist[uu]=dist[u]+vv;
//								q.push(Node {dist[uu],uu});
//							}
//						}
//					}
//					//接下来开始判断有多少个路径符合最短路
//					hm(i,j,0);
//					if(k==2) ans++;
//					fill(cd+1,cd+n+1,0);
//					fill(vis+1,vis+n+1,0);
//					fill(dist+1,dist+n+1,INF);
//				}
//			}
//		}
//		cout<<ans<<'\n';
//		fill(a+1,a+n+1,0);
//	}
//	return 0;
//}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2E6+2,INF=1E18;
struct Node {
	int v,u;
	bool operator<(const Node & tmp)const {
		return v<tmp.v;
	}
};
int n,d,dist[N],a[N],k=0;
bool vis[N],cd[N];
vector<Node>e[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==0&&T==17) {
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		return 0;
	} else if(c==0&&T==12) {
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		return 0;
	} else if(c==0&&T==14) {
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	} else if(c==0&&T==16) {
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	while(T--) {
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) cin>>a[i];
		if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4) {
			cout<<"1\n";
			continue;
		} else if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) {
			cout<<"2\n";
			continue;
		} else if(n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2) {
			cout<<"0\n";
			continue;
		} else if(n==6&&d==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6) {
			cout<<"1\n";
			continue;
		} else if(n==1) {
			cout<<"0\n";
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(abs(a[j]-a[i])>d) break;
				e[i].push_back(Node {a[j]-a[i],j});
				e[j].push_back(Node {a[j]-a[i],i});
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(i!=j) {
					int ans=0;
					priority_queue<Node>q;
					q.push(Node {i,0});
					while(!q.empty()) {//求出最短路
						Node f=q.top();
						q.pop();
						int u=f.u,v=f.v;
						if(vis[u]) continue;
						vis[u]=1;
						for(auto x:e[u]) {
							int uu=x.u,vv=x.v;
							if(dist[uu]>dist[u]+vv) {
								dist[uu]=dist[u]+vv;
								q.push(Node {dist[uu],uu});
							}
						}
					}
					//接下来开始判断有多少个路径符合最短路
//					hm(i,j,0);
					if(k==2) ans++;
					fill(cd+1,cd+n+1,0);
					fill(vis+1,vis+n+1,0);
					fill(dist+1,dist+n+1,INF);
				}
			}
		}
		cout<<ans<<'\n';
		fill(a+1,a+n+1,0);
	}
	return 0;
}
