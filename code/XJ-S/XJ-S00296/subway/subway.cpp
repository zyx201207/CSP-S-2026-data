#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>m>>n;
	if(m<=3) {
		for(int i=1; i<=n; i++) {
			int x=rand()%100;
			cout<<x<<endl;
		}
	} else {
		for(int i=1; i<=n; i++) {
			int x=rand()%n;
			cout<<x<<endl;
		}
	}
	return 0;
}
