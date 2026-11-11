#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,st,se,k[505];
ll w[1005];
ll ans=0x3f3f3f3f3f3f3f3f;
bool vis[1005];
struct spo {
	ll x;
	int to;
};
struct zhan {
	spo lu[25];
	int cl=0;
} a[1005];
struct xian {
	spo z[1005];
} b[505];
void dfx(int x,ll stp) {
	if(x==se) {
		ans=min(stp,ans);
		return ;
	}
	for(int i=1; i<=a[x].cl; ++i) {
		int xx=a[x].lu[i].to;
		for(int j=1; j<=k[xx]; ++j) {
			if(vis[b[xx].z[j].to]==0){
				vis[b[xx].z[j].to]=1;
				dfx(b[xx].z[j].to,a[x].lu[i].x+b[xx].z[j].x+stp);
				vis[b[xx].z[j].to]=0;
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) {
		cin>>w[i];
	}
	for(int i=1; i<=n; ++i) {
		cin>>k[i];
		for(int j=1; j<=k[i]; ++j) {
			ll x,tt;
			cin>>tt>>x;
			b[i].z[j].to=tt;
			b[i].z[j].x=x;
			a[tt].cl++;
			a[tt].lu[a[tt].cl].to=i;
			a[tt].lu[a[tt].cl].x=x;
		}
	}
	for(int i=1; i<=q; ++i) {
		memset(vis,0,sizeof vis);
		ans=0x3f3f3f3f3f3f3f3f;
		cin>>st>>se;
		dfx(st,0);
		cout<<ans+w[st]+w[se]<<'\n';
	}
	return 0;
}
