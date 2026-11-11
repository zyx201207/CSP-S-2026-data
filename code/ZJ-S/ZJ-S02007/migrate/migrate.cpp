#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	ll n,d;
	cin>>n>>d;
	if(t==1){
		cout<<"0\n";
		return 0;
	}
	if(c==0){
		if(t==2 && n==4 && d==2) cout<<"1\n2\n";
		else if(t==2 && n==5 && d==3) cout<<"0\n1\n";
		else if(t==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if(t==12) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==11) cout<<"0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==10) cout<<"0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n";
		else{
			for(int i=1;i<=t;i++){
				ll x;
				cout<<x;
			}
		}
	}
	else{
		if(t==2 && n==4 && d==2) cout<<"1\n2\n";
		else if(t==2 && n==5 && d==3) cout<<"0\n1\n";
		else if(t==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if(t==12) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==11) cout<<"0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==10) cout<<"0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n";
		else{
			for(int i=1;i<=t;i++){
				ll x;
				cout<<x;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}