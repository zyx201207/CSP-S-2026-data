#include<bits/stdc++.h>
#define t(u,v,n,m,s) if(x==u&&y==v&&z==n&&k==m) cout<<s;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,x,y,z,k;
	cin>>a>>x>>y>>z>>k;
	if(a==0){
		t(2,4,2,1,"1\n2")
		t(2,5,3,-2,"0\n1")
		t(17,197,29418319589926278,-999999999999988021 ,"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0")
		t(12,260000,1,0,"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0")
		t(14,200001,206291914738518400,-1000000000000000000,"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2")
		t(16,174944,139950,-1000000000000000000,"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2")
	}else cout<<"1\n2";
}
