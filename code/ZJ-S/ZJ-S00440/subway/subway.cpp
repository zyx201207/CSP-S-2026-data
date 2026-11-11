#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +5,M=500+5;
struct e{
	int a,t;
};
int x,y,k,n,m,c,d,q,w[N],mi[N];
vector<e> b[M],s[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
void df(int z){
	p.push({mi[z],z});
	while(!p.empty()){
		pair<int,int> g=p.top();
		p.pop();
		if(mi[g.second]!=0x3f3f3f3f&&mi[g.second]!=g.first) continue;
		for(auto h:s[g.second]){
			for(auto f:b[h.a]){
				if(f.a==g.second||mi[g.second]+f.t+h.t>=mi[f.a]) continue;
				mi[f.a]=mi[g.second]+f.t+h.t;
				p.push({mi[f.a],f.a});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>x>>y;
			b[i].push_back((e){x,y});
			s[x].push_back((e){i,y});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=m;j++) mi[j]=0x3f3f3f3f;
		mi[x]=w[x];
		df(x);
//		for(int j=1;j<=m;j++) cout<<mi[j]<<' ';
//		cout<<'\n';
		cout<<mi[y]+w[y]<<'\n';
	}
	return 0;
}
