#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	sort(w+1,w+1+m);
	for(int i=1;i<=3;i++){
		cout<<w[1]+w[2]+w[3]+w[4]+w[5+i]+w[6+i]<<endl;;
	}
	return 0;
} 
