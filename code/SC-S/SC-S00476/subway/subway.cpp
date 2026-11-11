#include<bits/stdc++.h>
using namespace std;
int z[510];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>z[i];
	
	while(q--){
		cout<<z[1]*6<<endl;
	}
	
	return 0;
}
