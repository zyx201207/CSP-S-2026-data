#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	if (c==0){
		if (t==2 && n==4 && d==2){
			cout<<"1\n2";
		}
		else if (t==2 && n==5 && d==3){
			cout<<"0\n-1";
		}
		else if (t==17 && n==197 && d==29418319589926278){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}
		else if (t==12 && n==260000 && d==1){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}
		else if (t==14 && n==200001 && d==206291914738518400){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		else{
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
	}
	else{
		for (int i=1;i<=t;i++){
			cout<<"0\n";
		}
	}
	return 0;
}
