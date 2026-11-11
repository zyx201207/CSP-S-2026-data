#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,d;
int a[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int m=a[2]-a[1];
		//cout<<m<<endl;
		//cout<<d<<" "<<n-3;
		if(d>=m*2&&d<m*3){
			cout<<n-3<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
