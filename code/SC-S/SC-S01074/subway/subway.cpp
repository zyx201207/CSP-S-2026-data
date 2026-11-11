#include<bits/stdc++.h>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long lint;

const int N=5e5+7,inf=0x3f3f3f3f;

struct Pair{
	int l;
	lint t;
};

int n,m,d,q;
int k[550],w[N];
lint mp[550][550];

vector<Pair> ln[550];

void floyd(){
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	memset(mp,0x3f,sizeof mp);
	
	int c; cin>>c>>m>>n>>d>>q;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int v;
	lint t;
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v>>t;
			ln[v].push_back({i,t});
		}
	}
	
	for(int i=1;i<=n;i++){
		if(ln[i].size()>1)
		for(Pair r:ln[i]){
			for(Pair u:ln[i]){
				if(u.l==r.l) mp[r.l][u.l]=0;
				mp[r.l][u.l]=min(mp[r.l][u.l],u.t+r.t);
			}
		}
	}
	
	floyd();
	
	int x,y;
	lint res=0;
	while(q--){
		res=0; cin>>x>>y;
		res+=w[x]+w[y];
		t=inf;
		for(Pair r:ln[x]){
			for(Pair u:ln[y]){
				t=min(t,r.t+u.t+mp[r.l][u.l]);
			}
		}
		cout<<res+t<<"\n";
		
	}
	
	return 0;
}