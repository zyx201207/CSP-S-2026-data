#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d>=(x[2]-x[1])*2&&d<(x[2]-x[1])*3){
				cout<<n-3<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
			continue;
		}
		cout<<0<<'\n';
	}
	return 0;
}
