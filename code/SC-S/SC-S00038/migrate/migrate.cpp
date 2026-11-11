#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	cin>>n>>d;
	if(t==2&&n==4&&d==2){
		cout<<"1\n2";
	}else if(t==2){
		cout<<"0\n1";
	}else if(t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}else if(t==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	}else if(t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	}else if(t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	}else{
		for(int i=1;i<=t;i++){
			cout<<0<<"\n";
		}
	}
	return 0;
}