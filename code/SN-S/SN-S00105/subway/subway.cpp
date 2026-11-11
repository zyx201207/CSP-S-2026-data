#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,n,m,d,q;
vector<int> a[510];
vector<int> t[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			a[i].push_back(x);
		}
	}
	return 0;
} 
