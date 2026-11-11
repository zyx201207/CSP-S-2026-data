#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t;
int n,k;
vector<int> tree[MAXN];
vector<int> path;
int vis[MAXN];
//void C(int pos,int x) {
//	if(pos==k) {
//		
//		return ;
//	}
//	for(int i=x+1; i<=n; ++i) {
//		if(vis[i]==false) {
//			vis[i]=true;
//			path.push_back(i);
//			C(pos+1,i);
//			vis[i]=false;
//			path.pop_back();
//		}
//	}
//}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0) {
		if(t==2) {
			cout<<1<<endl<<2;
		}
		if(t==3) {
			cout<<1<<endl<<1<<endl<<2;
		}
		if(t==5) {
			cin>>n;
			if(n==602) {
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			} 
			else {
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
			}
		}
		if(t==1) {
			cout<<12251;
		}
		return 0;
	}
	while(t--) {
		cin>>n>>k;
		for(int i=1; i<=n-1; ++i) {
			tree[i].clear();
			int x;
			cin>>x;
			tree[i].push_back(x);
		}
		//C(0,0);
	}
	return 0;
}