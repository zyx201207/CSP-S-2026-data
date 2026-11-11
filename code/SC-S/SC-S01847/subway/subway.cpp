#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+1;

ll w[N],a[100][N],t[N][100],tran[N],x[N],v[N];
vector<int> g[N];
ll c,n,m,d,q;
struct Point{
	int f,trn;
};


int bfs(int b){
	Point po[N];
	po[1].f=b;
	po[1].trn=0;
	int l=1,r=1,cnt=0;
	while(l<=r){
		int x=po[l].f,xl=po[l].trn;
		l++;
		if(v[x]==1)continue;
		v[x]=1;
		for(int i=1;i<=tran[x];i++){
			r++;
			if(tran[x]>=2 && i!=1) {
				po[r].f=g[x][i];
				po[r].trn=xl+1;
			}
			po[r].f=g[x][i];
			po[r].trn=xl;
		}
		return po[r].trn;
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			int s,y;
			cin>>s>>y;
			tran[s]++;
			a[i][j]=s;
			t[i][j]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<x[i];j++){
			g[a[i][j]].push_back(a[i][j+1]);
			g[a[i][j+1]].push_back(a[i][j]);
		}
	}
	while(q--){
		memset(v,0,sizeof v);
		int be,en;
		cin>>be>>en;
		int ans=0;
		ans+=w[be];
		ans+=w[en];
		int h=bfs(be);
		ans+=t[1][1]*h*2;
		cout<<ans<<"\n";
	}
	
	return 0;
} 