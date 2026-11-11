#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=500005,INF=0x3f3f3f3f;
inline ll read() {
	ll x=0,f=1;
	ll ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline ll write(ll x) {
	if(x<0) {
		x=-x;
		putchar('-');
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}
ll c,n,m,d,q;
ll w[N],dis[20005],vis[N];
map<ll,ll> dism[20005];
vector<ll> a[20005];
vector<pair<ll,ll> > b[505];
priority_queue<pair<ll,pair<ll,ll > > ,vector<pair<ll,pair<ll,ll > > >,greater<pair<ll,pair<ll,ll > > > > qq;
void dijkstra() {
	while(!qq.empty()) {
//		cout<<qq.size()<<endl;
		ll u=qq.top().second.first,w=qq.top().first,lzt=qq.top().second.second;
		qq.pop();
//		cout<<"+++"<<u<<' '<<w<<' '<<lzt<<endl;
		for(ll j=0; j<a[u].size(); j++) {
			ll zt=a[u][j];
//				cout<<"ZT:"<<lzt<<' '<<zt<<endl;
			if(lzt==zt) {
				for(ll k=0; k<b[zt].size(); k++) {
					ll v=b[zt][k].first,nw=b[zt][k].second;
//						cout<<"__"<<v<<endl;
					if(w+nw<dis[v]) {
						dis[v]=w+nw;
						qq.push(make_pair(dis[v],make_pair(v,zt)));
					}
				}
			} else {
				for(ll k=0; k<b[zt].size(); k++) {
					ll v=b[zt][k].first,nw=b[zt][k].second;
//						cout<<"!!"<<v<<' '<<b[zt][k].second<<' ';
//						for(int kk=0; kk<b[lzt].size(); kk++) {
//							if(b[lzt][kk].first==u) {
//								nw+=b[lzt][kk].second;
//								cout<<b[lzt][kk].second<<' ';
//								break;
//							}
//						}
					for(ll kk=0; kk<b[zt].size(); kk++) {
						if(b[zt][kk].first==u) {
							nw+=b[zt][kk].second;
//								cout<<b[zt][kk].second<<endl;
							break;
						}
					}
//						cout<<"~~~"<<w<<' '<<nw<<' '<<dis[v]<<endl;
					if(w+nw<dis[v]) {
						dis[v]=w+nw;
						qq.push(make_pair(dis[v],make_pair(v,zt)));
					}
				}
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(ll i=1; i<=m; i++) {
		w[i]=read();
	}
//	if(m<=20000) {
	for(ll i=1; i<=n; i++) {
		ll k,ai[1005],ti[1005];
		k=read();
		for(ll j=1; j<=k; j++) {
			ai[j]=read();
			ti[j]=read();
		}
		for(ll j=1; j<=k; j++) {
			a[ai[j]].push_back(i);
			b[i].push_back(make_pair(ai[j],ti[j]));
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<i<<' '<<j<<endl;
//			for(int k=0;k<a[i][j].size();k++){
//				cout<<a[i][j][k]<<' ';
//			}
//			cout<<endl;
//		}
//	}
	for(ll i=1; i<=q; i++) {
		ll fs,fe;
		fs=read();
		fe=read();
		if(dism[fs][fe]) {
			write(dism[fs][fe]);
			putchar(endl);
			continue;
		}
		for(ll j=0; j<a[fs].size(); j++) {
			for(ll k=0; k<b[a[fs][j]].size(); k++) {
				if(b[a[fs][j]][k].first==fs) {
//					cout<<b[a[fs][j]][k].second<<endl;
					qq.push(make_pair(b[a[fs][j]][k].second,make_pair(fs,a[fs][j])));
					break;
				}
			}
		}
		for(ll j=1; j<=m; j++) {
			dis[j]=INF;
		}
		dis[fs]=0;
		dijkstra();
		for(ll j=1; j<=m; j++) {
			dism[fs][j]=dis[j]+w[fs]+w[j];
		}
		write(dis[fe]+w[fs]+w[fe]);
		putchar(endl);
	}
//	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
