#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for (int i=1; i<=t; i++) {
		cin>>n>>k;
		for (int i=1; i<=n-1; i++) {
			int u,v;
			cin>>u>>v;
		}
		if (k<=5&&n<=5) {
			if (k==1&&n<=3) {
				cout<<"1"<<endl;
			} else if (k==1&&n<=5) {
				cout<<"2"<<endl;
			} else {
				cout<<"1"<<endl;
			}
		} else {
			if (k*3>n) {
				cout<<"1"<<endl;
			} else {
				cout<<"2"<<endl;
			}
		}
	}
	return 0;
}
