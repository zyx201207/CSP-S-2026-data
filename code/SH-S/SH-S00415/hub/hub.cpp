#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;

int c,t,n,k;
vector<int> E[N];

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<=n-1;i++) {
			int u,v;
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		if(c==13||c==14) {
			int m=n/2;
			if(k==n)cout<<0<<'\n';
			else if(k>=m)cout<<1<<'\n';
			else {
				if(k==1) cout<<m/2+1<<'\n';
				else {
					if((m-k)%4==0)cout<<(m-k)/4+1<<'\n';
					else cout<<(m-k)/4+2<<'\n';
				}
			}
		}
	}
	return 0;
}
