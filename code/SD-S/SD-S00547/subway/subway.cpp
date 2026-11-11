#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,time;
};
int c,n,m,d,q,k[505],w[500005];
vector<node> v[500005];
long long t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(t,0x3f,sizeof(t));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		t[i][i]=0;
		cin>>k[i];
		node s;
		for(int j=1;j<=k[i];j++){
			cin>>s.u>>s.time;
			v[s.u].push_back({i,s.time});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto j:v[i])
			for(auto l:v[i]){
				if(j.u==l.u) continue;
				t[j.u][l.u]=min(t[j.u][l.u],1ll*j.time+l.time);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				t[i][j]=t[j][i]=min(t[i][j],t[i][k]+t[k][j]);
	long long minn;
	for(int i=1;i<=q;i++){
		int x,y;
		minn=0x7fffffffffffffff;
		cin>>x>>y; 
		for(auto j:v[x]) for(auto k:v[y]){
			minn=min(minn,t[j.u][k.u]+w[x]+w[y]+j.time+k.time);
		}
		cout<<minn<<'\n';
	}
	return 0;
}
