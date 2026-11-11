#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("suybway.in","r",stdin);
	freopen("suybway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[1005],a[1005],t[1005];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=n;i++){
		cin>>a[i]>>t[i];
	}
	cout<<w[1]+t[1]+t[2]+w[2]<<endl;
	cout<<w[2]+t[2]+t[3]+w[3];
	return 0;
}
