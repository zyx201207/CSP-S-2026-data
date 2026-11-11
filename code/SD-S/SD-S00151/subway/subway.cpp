#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e5;
const int M=1e3+1e2;
int w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=w[i];
	}
	while(q--){
		cout<<sum<<"\n";
	}
	return 0;
}

