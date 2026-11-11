#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
#define int long long
long long c,n,m,d1,q1;
long long dis[N][N],d[N];
long long ans=0,u;
struct node{
	long long x,a,b;
};
vector<node> p;
struct node1{
	long long x;
	long long y;
};
vector<node1> q[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d1>>q1;
	for (int i=1;i<=m;i++) cin>>d[i];
	for (int i=1;i<=n;i++){
		int n1;
		cin>>n1;
		while (n1--){
			int o,f;
			cin>>o>>f;
			p.push_back({i,o,f});
			ans++;
		}
		for (int j=ans-1-n1;j<ans;j++){
			for (int k=j+1;k<ans;k++){
				q[p[j].a].push_back({p[k].a,0});
				q[p[k].a].push_back({p[j].a,0});
				u+=2;
			}
		}
	}
	for (int i=0;i<=ans;i++){
		for (int j=i+1;j<ans;j++){
			if (p[i].x==p[j].x) continue;
			q[p[j].a].push_back({p[i].a,p[j].b+p[i].b});
			q[p[i].a].push_back({p[j].a,p[i].b+p[j].b});
			u+=2;
		}
	}
	for (int i=1;i<m;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<u;k++){
				dis[i][j]=min(dis[i][j],dis[i][q[k].x]+q[q[k].x].y);
			}
		}
	}
	for (int i=1;i<=q1;i++){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]+d[l]+d[r]<<endl;
	}
	return 0;
}
