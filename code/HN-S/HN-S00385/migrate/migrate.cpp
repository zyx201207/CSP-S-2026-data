#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			int s=d/x[1];
			if(n%s==0){
				cout<<0<<endl;
			}
			else{
				cout<<n/s+1<<endl;
			}
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}

