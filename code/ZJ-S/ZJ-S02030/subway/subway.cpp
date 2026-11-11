#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		int k;
		cin>>k;
		for(int i=1;i<=2*k;i++){
			int x;
			cin>>x;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<d-l-r<<"\n";
	}
	return 0;
}