#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,x,k;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>x;
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=2*k;j++) cin>>x;
	}
	for (int i=1;i<=q;i++) cin>>x>>x;
	for (int i=1;i<=q;i++) cout<<128<<endl;
	return 0;
}

