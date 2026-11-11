#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct sw{
	int a,t;
}v[500][20005];
int n,m,d,q,k;
int w[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>d>>q;
	for(int i=0; i<m; i++) cin>>w[i];
	for(int i=0; i<n; i++) {
		cin>>k;
		for(int j=0; j<k; j++)
			cin>>v[i][j].a>>v[i][j].t;
	}
	
	return 0;
}