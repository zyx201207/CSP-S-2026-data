#include <bits/stdc++.h>
using namespace std;
int c,n,d;
long long m,q,k,x,y;
int w[600009],a[600009],t[600009];
long long sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while (q--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		cin>>x>>y;	
		cout<<w[1]<<t[1]<<t[2]<<w[2];
		sum=w[1]+t[1]+t[2]+w[2];
		cout<<sum<<endl;
	}

	return 0;
}
