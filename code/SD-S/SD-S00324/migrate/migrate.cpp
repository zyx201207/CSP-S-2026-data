#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int c,t,n;
ll d,x[2000005],cha;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cha=abs(x[1]-x[2]);
		if(2*d<cha)cout<<0<<'\n';
		else cout<<n-cha/d-1<<'\n';
	}
	return 0;
}

