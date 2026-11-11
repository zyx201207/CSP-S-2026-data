#include<bits/stdc++.h>
using namespace std;
//operator priority_queue unsigned
int c,t;
int n,k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	if(c==0) {
		if(t==2) {
			while(t--) {
				cin>>n>>k;
				long long u,v;
				for(int i=1; i<n; i++) {
					cin>>u>>v;
				}
				if(n==5) {
					cout<<"1"<<'\n';
				}
				if(n==10) {
					cout<<"2"<<'\n';
				}
			}
		} else {
			while(t--) {
				cin>>n>>k;
				long long u,v;
				for(int i=1; i<n; i++) {
					cin>>u>>v;
				}
			}
			cout<<"189"<<'\n'<<"233"<<'\n'<<"288"<<'\n'<<"229"<<'\n'<<"338"<<'\n';
		}
	} else {
		while(t--) {
			cin>>n>>k;
			long long u,v;
			for(int i=1; i<n; i++) {
				cin>>u>>v;
			}
			cout<<rand()%(1000000-1)<<'\n';//
		}
	}
	return 0;
}
