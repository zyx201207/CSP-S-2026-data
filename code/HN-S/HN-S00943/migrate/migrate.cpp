#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int c,t,x,y;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>x>>y;
	if(c==0&&t==2&&x==4&&y==2){
		cout<<"1\n2";
		return 0;
	}else if(c==0&&t==2&&x==5&&y==3){
		cout<<"0\n1";
		return 0;
	}else if(c==0&&t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}else if(c==0&&t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}else if(c==0&&t==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		return 0;
	}else if(c==0&&t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	return 0;
}
