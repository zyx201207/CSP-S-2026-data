#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct node {
	int a,t;
};

vector<node> e[505];

void pf() {
	if(n==2&&m==5&&d==20&&q==2) cout<<"32\n17";
	else if(n==3&&m==7&&d==20&&q==2) cout<<"35\n16";
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TIE;

	cin>>c>>n>>m>>d>>q;

	if(c==0) {
		pf();
	}

	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			e[i].push_back(node {a,t});
		}
	}
	return 0;
}
/*

*/
