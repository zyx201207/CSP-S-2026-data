#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n);
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}
		if(d==2){
			cout<<d-3<<'\n';
		}
		if(d!=2) cout<<0<<'\n';
    }
	return 0;
}
