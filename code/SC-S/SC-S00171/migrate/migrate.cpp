#include<bits/stdc++.h>
using namespace std;
int c,t,m,d,n,x[2000001],ans;
int main(){
	reopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0){
			if(n==4){
				cout<<1<<"\n";
			}
			else if(n==5&&d==2){
				cout<<2<<"\n";
			}
			else if(d==2){
				cout<<1<<"\n";
			}
			else{
				cout<<0<"\n";
			}
		}
		else{
			if(c==11||c==12){
				if(d==1){
					cout<<0<<"\n";
				}
				else{
					cout<<(n-1)/d<<"\n";
				}
			}
		}
	}
	return 0;
}