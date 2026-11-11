#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,t,d;
	ll x[n];
	int c;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1||n==2){
		cout<<0;
		return 0;
		if(n==3){
			if((x[2]-x[1]+x[3]-x[2])==(x[3]-x[1])&&((x[3]-x[1])<=d)){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
		if(n==4){
			if((x[2]-x[1]+x[3]-x[2]+x[4]-x[3])==(x[4]-x[1])&&((x[4]-x[1])==(x[2]-x[1]+x[4]-x[2]))&&((x[4]-x[1])==(x[3]-x[1]+x[4]-x[3]))&&((x[4]-x[1])<=d)){
				cout<<0;
				return 0;
			}
			if((x[2]-x[1]+x[3]-x[2]+x[4]-x[3])!=(x[4]-x[1])&&((x[4]-x[1])==(x[2]-x[1]+x[4]-x[2]))&&((x[4]-x[1])==(x[3]-x[1]+x[4]-x[3]))&&((x[4]-x[1])<=d)){
				cout<<1;
				return 0;
			}
			if((x[2]-x[1]+x[3]-x[2]+x[4]-x[3])==(x[4]-x[1])&&((x[4]-x[1])!=(x[2]-x[1]+x[4]-x[2]))&&((x[4]-x[1])==(x[3]-x[1]+x[4]-x[3]))&&((x[4]-x[1])<=d)){
				cout<<1;
				return 0;
			}
			if((x[2]-x[1]+x[3]-x[2]+x[4]-x[3])==(x[4]-x[1])&&((x[4]-x[1])==(x[2]-x[1]+x[4]-x[2]))&&((x[4]-x[1])!=(x[3]-x[1]+x[4]-x[3]))&&((x[4]-x[1])<=d)){
				cout<<1;
				return 0;
			}
			if((x[2]-x[1]+x[3]-x[2]+x[4]-x[3])==(x[4]-x[1])&&((x[4]-x[1])==(x[2]-x[1]+x[4]-x[2]))&&((x[4]-x[1])==(x[3]-x[1]+x[4]-x[3]))&&((x[4]-x[1])>d)){
				cout<<0;
				return 0;
			}	
		}
	}
		fclose(stdin);
		fclose(stdout);
		return 0;
}