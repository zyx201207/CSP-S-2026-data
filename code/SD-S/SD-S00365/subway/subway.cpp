#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500025],a[500025],t[500025];
long long sum;
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		sum+=t[i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
	}
	while(q--){
		cin>>x>>y;
	}
	cout<<sum<<endl;
	return 0;
}

