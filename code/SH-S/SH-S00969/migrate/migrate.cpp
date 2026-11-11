#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int t;cin>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int diff=a[2]-a[1];
		bool f=1;
		for(int i=2;i<=n-1;i++){
			if(diff!=a[i+1]-a[i]) f=0;
		}
		if(f){
			if(d<diff) cout<<0<<endl;
		}
	}
	return 0;
}
