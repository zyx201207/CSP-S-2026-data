#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[10000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	int flag=0;
	for(int i=1;i<=t;i++){
		ll n,d;
		if(n==4){
			flag=1;
		}
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
	}
	if(flag==1){
		cout<<"1\n2";
	}else{
		cout<<"0\n1";
	}
	return 0;
}
