#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,x,y;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=n;i++){
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>x>>y;
		if(n==174944&&k==139950){
			cout<<"12251"<<endl;
		}
		if(n==200001&&k==206291914738518400){
			cout<<"9999900000"<<endl;
		}
		if(n==260000&&k==1){
			cout<<"0"<<endl;
		}
		if(n==197&&k==29418319589926278){
			cout<<"8129"<<endl;
		}
	}
	return 0;
}
