#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int t;
	cin>>t;
	while(t--){
		int n;
		int d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int m=a[2]-a[1];
		if(d>=2*m && d<3*m){
			cout<<n-3<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
