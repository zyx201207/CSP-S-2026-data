#include <bits/stdc++.h>
using namespace std;
int c,t;
int x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			int bj=x[2]-x[1];
			int fd=d/bj;
			if(d<bj||(n-1)%fd==0){
				cout<<0<<endl;
				continue;
			}
			cout<<(n-1)%fd<<endl;
		}
	}
	return 0;
} 
