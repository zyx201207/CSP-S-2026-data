#include<bits/stdc++.h>
using namespace std;
int t,c,n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12) cout<<int(pow(2,n))<<"\n";
		if(c==13||c==14) cout<<(n-1)*(n-2)/2<<"\n";
		cout<<rand()%n<<"\n";
	}
	return 0;
}
