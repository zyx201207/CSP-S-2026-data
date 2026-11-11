#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>m>>n;
	for(int i=1; i<=n; i++) {
		int x=rand()%n;
		cout<<x<<endl;
	}
	return 0;
}
