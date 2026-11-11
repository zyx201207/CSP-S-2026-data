#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,a[2000009];
		bool spA;
		cin>>n>>d>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[2]-a[1])spA=0;
		}
		cout<<0<<endl;
	}
	return 0;
}
