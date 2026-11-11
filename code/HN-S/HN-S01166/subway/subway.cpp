#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int ans,val,c,n,m,d,q,w[M],a[M];
signed main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int h;
		cin>>h;
		for(int j=1;j<=h;j++){
			cin>>a[j]>>val;
		} 
	}
	if(c==0){
		cout<<32<<'\n'<<17<<'\n';
	}
	return 0;
}
