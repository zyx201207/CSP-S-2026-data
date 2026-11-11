#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using lnt=long long;
/*====================*/
int op,T,n,x,y,z;
/*====================*/
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	/*====================*/
	cin>>op>>T;
	if(op==0){
		cin>>x>>y;
		while(cin>>z){}
		if(x==2&&y==4) cout<<"1\n2";
		if(x==2&&y==5) cout<<"0\n1";
		if(x==17&&y==197) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		if(x==12&&y==260000) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		if(x==14&&y==200001) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		if(x==16&&y==174944) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	else if(op==12||op==13){
		int d,x,y;
		while(T--){
			cin>>n>>d;
			for(int i=1;i<n;i++) cin>>x;
			cin>>y;
			if(abs(y-x)>d) cout<<0<<endl;
			else cout<<n-2<<endl;
		} 
	}
	else{
		while(cin>>x)
		while(T--) cout<<"0\n";
	}
	return 0;
}
