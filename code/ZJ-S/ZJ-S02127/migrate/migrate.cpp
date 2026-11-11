#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int c,t,n;
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	if(c==11||c==12){
		cin>>t;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			long long dc=x[2]-x[1];
			if(dc>d){
				cout<<0<<"\n";
				continue;
			}
		}
	}
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
	}
	return 0;
}
