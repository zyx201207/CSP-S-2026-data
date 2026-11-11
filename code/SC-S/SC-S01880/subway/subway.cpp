#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
const int A=250010;
const int B=7e2+10;
const int N=1e9+10;
ll c,m,n,d,q,k,ans,z;
ll w[A],jl[A],t[B][A],l[B][B];
vector<ll>a[B],lz[A],ls[A];
vector<ll>tu[B],ts[B];
bool vis[B];
priority_queue<pl,vector<pl>,less<pl>> dui;
void djs(ll p){
	memset(vis,0,sizeof(vis));
	memset(jl,N,sizeof(jl));
	ll ss=tu[p].size();
	ll x,y;
	jl[p]=0;vis[p]=1;
	for(int i=0;i<ss;i++){
		jl[tu[p][i]]=ts[p][i];
		dui.push({ts[p][i],tu[p][i]});
	}
	while(!dui.empty()){
		x=dui.top().first,y=dui.top().second;
		dui.pop();
		if(vis[y])continue;
		vis[y]=1;
		ss=tu[y].size();
		for(int i=0;i<ss;i++){
			if(!vis[tu[y][i]]){
				jl[tu[y][i]]=min(ts[y][i]+x,jl[tu[y][i]]);
				dui.push({jl[tu[y][i]],tu[y][i]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i][x]=y;
			lz[x].push_back(i);
			ls[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<lz[i].size();j++){
			for(int ij=0;ij<lz[i].size();ij++){
				if(j!=ij){
					tu[lz[i][j]].push_back(lz[i][ij]);
					ts[lz[i][j]].push_back(t[lz[i][j]][i]+t[lz[i][ij]][i]);
					tu[lz[i][ij]].push_back(lz[i][j]);
					ts[lz[i][ij]].push_back(t[lz[i][j]][i]+t[lz[i][ij]][i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		djs(1LL*i);
		for(int j=1;j<=n;j++){
			l[i][j]=jl[j];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];z=0;
		for(int i=1;i<=lz[x].size();i++){
			for(int j=1;j<=lz[y].size();j++){
				if(lz[x][i]==lz[y][j]){
					z=min(z,ls[x][i]+ls[y][j]);
				}else{
					z=min(z,ls[x][i]+ls[y][j],l[lz[x][i]][lz[y][j]]);
				}
			}
		}
		ans+=z;
		cout<<ans<<'\n';
	}
	return 0;
}
