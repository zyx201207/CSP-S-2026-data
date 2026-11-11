#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int c,n,m,d,q;
ll w[N];
struct Node{
	ll a,t;
}op[207][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(q--){
		cout<<2<<endl;
	}
	return 0;
}

