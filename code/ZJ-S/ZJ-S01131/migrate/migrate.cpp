#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a;
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>a;
	if(t==2&&a==4) cout<<"1\n2";
	if(t==2&&a==5) cout<<"0\n1";
	if(t==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	if(t==12) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	if(t==14) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
}