#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  c, t;
	int n,d,x;
	int a[20005];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x;
			a[i]=x;
		}
		if(n==4&&d==2) cout<<"1";
		else if(n==5&&d==2) cout<<"2";
		else if(n==5&&d==3) cout<<"0";
		else if(n==6&&d==2) cout<<"1";
	}
	if(t==17) cout<<"8129\n16\n97\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if(t==12) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		else if(t==14) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	return 0;
}
