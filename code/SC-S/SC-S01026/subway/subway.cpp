#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int M=5e5+5;
struct node{
	ll to,val;
};
ll di[505][505];
vector<node> s[M],dn[505];
ll c,n,m,d,q,w[M];
bool in[M][505],din[505][505];
ll ans[505],inq[505];
queue<ll> pq;
void work(ll x){
	memset(ans,0x3f,sizeof(ans));
	ans[x]=0;
	inq[x]=1;
	pq.push(x);
	while(!pq.empty()){
		ll now=pq.front();pq.pop();
		inq[now]=0;
		for(ll i=0;i<dn[now].size();i++){
			ll to=dn[now][i].to,val=dn[now][i].val;
			if(ans[to]>ans[now]+val){
				ans[to]=ans[now]+val;
				if(!inq[to]) pq.push(to);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(di,0x3f3f,sizeof(di));
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll step,t;
			cin>>step>>t;
			for(ll l=0;l<s[step].size();l++){
				ll to=s[step][l].to,val=s[step][l].val;
				din[to][i]=1;
				din[i][to]=1;
				di[i][to]=min(di[i][to],val+t);
				di[to][i]=min(di[to][i],val+t);
			}
			s[step].push_back({i,t});
			in[step][i]=1;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) continue;
			if(din[i][j]) dn[i].push_back({j,di[i][j]});
			if(din[j][i]) dn[j].push_back({i,di[j][i]});
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y,ansi=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(int i=0;i<s[x].size();i++){
			work(s[x][i].to);
			for(int j=0;j<s[y].size();j++){
				ansi=min(ansi,ans[s[y][j].to]+s[x][i].val+s[y][j].val);
			}
		}
		cout<<ansi+w[x]+w[y]<<endl;
	}
	return 0;
}