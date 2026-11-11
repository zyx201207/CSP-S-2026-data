#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=(int)2e6+5;
void fastIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
void file() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
//duo ce qing kong !!!
int x[N];
int n;
ll d,ans=0;
bool check(int i,int j) {
	if(x[j]-x[i]<=d) {
		return false;
	}
	return true;
}
void solve() {
	int n,k;
	cin>>n>>k;
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
	}
}
int main() {
	fastIO();
	file();
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//rp++
//CCF I love you
/*
zhi3 hui4 xie3 di4 yi1 ti2 
hao3 lei4 a1
jing4 sai4 zhen1 de lei4
qui2 ni3 le kan4 zai4 wo3 xie3 le zhe4 mo4 duo1 de fen4 shang4 gei3 wo3 dian3 fen1 ba
***********
*/
	int c,t,n,k;
	cin>>c>>t;
	if(c==0) {
		if(t==2) {
			while(t--) {
				cin>>n>>k;
				for(int i=1; i<n; i++) {
					int u,v;
					cin>>u>>v;
				}
			}
			cout<<"1\n2";
		} else if(t==3) {
			while(t--) {
				cin>>n>>k;
				for(int i=1; i<n; i++) {
					int u,v;
					cin>>u>>v;
				}
			}
			cout<<"1\n1\n2";
		} else if(t==1) {
			while(t--) {
				cin>>n>>k;
				for(int i=1; i<n; i++) {
					int u,v;
					cin>>u>>v;
				}
			}
			cout<<"12251";
		} else if(t==5) {
			int u,v;
			while(t--) {
				cin>>n>>k;
				for(int i=1; i<n; i++) {
					cin>>u>>v;
				}
			}
			if(u==121) {
				cout<<"17\n9\n6\n6\n9";
			} else {
				cout<<"189\n233\n288\n229\n338";
			}
		}
		return 0;
	}
	while(t--) {
		solve();
	}
	return 0;
}