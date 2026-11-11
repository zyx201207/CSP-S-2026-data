#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+505;
int c,n,m,d,q;
struct jb {
	int v,w;
//	int x;//0:to subway    i:to station i
};
vector<jb> vc[N];
struct ds {
	int d,z;
};
struct cmp {
	operator()(ds &a,ds &other) {
		return a.z>other.z;
	}
};
priority_queue<ds,vector<ds>,cmp> p;
int w[N];
int k,a,t,len;
int x,y,len2;
int r;
int last[N];
void dj() {
//	cout<<"x="<<x<<",y="<<y<<endl;
	while(!p.empty()) {
		ds bl=p.top();
		p.pop();
		if(last[bl.d]==r){
			continue;
		}
	//	cout<<"here is "<<bl.d<<" and my z is "<<bl.z<<endl;
		if(bl.d==y) {
			cout<<bl.z<<endl;
			return;
		}
		len2=vc[bl.d].size();
		for(int i=0; i<len2; i++) {
			if(vc[bl.d][i].v<=m&&vc[bl.d][i].v!=y) {
				continue;
			}
			if(last[vc[bl.d][i].v]!=r) {
				p.push({vc[bl.d][i].v,bl.z+vc[bl.d][i].w});
			//	cout<<"push "<<vc[bl.d][i].v<<" into queue,use "<<bl.z<<"+"<<vc[bl.d][i].w<<endl;
			}
		}
		last[bl.d]=r;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	//	cout<<i<<"'s w is "<<w[i]<<endl;
	}
	//cout<<"cin w is ok"<<endl;
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a>>t;
			len=vc[a].size();
			for(int l=0; l<len; l++) {
				vc[i+m].push_back({vc[a][l].v,vc[a][l].w+t-w[a]});
				vc[vc[a][l].v].push_back({i+m,vc[a][l].w+t-w[a]});
			//	cout<<vc[a][l].v<<" - "<<i+m<<" build a side and w is "<<vc[a][l].w+t-w[a]<<endl;
			}
			vc[i+m].push_back({a,t+w[a]});
			vc[a].push_back({i+m,t+w[a]});
		}
	}
	for(r=1; r<=q; r++) {
		cin>>x>>y;
		while(!p.empty()) {
			p.pop();
		}
		p.push({x,0});
		dj();
	}
	return 0;
}