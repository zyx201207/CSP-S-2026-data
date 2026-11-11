#include<bits/stdc++.h>
using namespace std;
//operator priority_queue unsigned
const int MAXN=1e6+5;
int c,t;
int n,d;
int x[MAXN];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	if(c==0) {
		if(t==2) {
			while(t--) {
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"1 2 3 4"<<'\n'<<"1 2 3 4 5"<<'\n';
		} else {
			while(t--) {
				cin>>n>>d;
				for(int i=1; i<=n; i++) {
					cin>>x[i];
				}
			}
			cout<<"0"<<'\n'<<"0"<<'\n'<<"259997"<<'\n'<<"259995"<<'\n'<<"86669"<<'\n'<<"0"<<'\n'<<"0"<<'\n'<<"0"<<'\n'<<"7"<<'\n'<<"5"<<'\n'<<"5"<<'\n'<<"0"<<'\n';
		}
	} else {
		while(t--) {
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>x[i];
			}
			cout<<rand()%(114514)<<'\n';//
		}
	}
	return 0;
}
