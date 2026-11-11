#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int w[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
}
