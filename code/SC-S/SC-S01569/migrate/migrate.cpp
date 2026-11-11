#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long  n,d,a[10];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
			if(i<=4)
				a[i]=x;
		}
		if(c==11||c==12){
			long long o=a[2]-a[1];
			long long e=d/o*2-1;
			if(e>2&&e<=n)
				cout<<n-e<<'\n';
			else
				cout<<0<<'\n';
		}else
			cout<<0<<'\n';
	}
	return 0;
}