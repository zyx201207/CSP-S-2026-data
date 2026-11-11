#include<bits/stdc++.h>
using namespace std;

const int N=505;
const int M=5e5+5;
const int D=25;
int c,n,m,d,q,ans=0;
int w[M],a[N][M],t[N][M],k[N];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int T;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int o=1;o<=n;o++) {
		cin>>k[o];
		for(int i=1;i<=k[o];i++) {
			cin>>a[o][i]>>t[o][i];
			T=t[o][i];
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		cout<<ans+T*(y-x)<<endl;
	}
	return 0;
}//hyw