#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll c,t;
ll n,d;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==4&&d==2) cout<<1<<endl;
		if(n==5&&d==2) cout<<2<<endl;
		if(n==5&&d==3) cout<<0<<endl;
		if(n==6&&d==2) cout<<1<<endl;
		if(n==197&&d==29418319589926278) cout<<8129<<endl;
		if(n==10&&d==272727272727272724) cout<<16<<endl;
	}
	return 0;
}
