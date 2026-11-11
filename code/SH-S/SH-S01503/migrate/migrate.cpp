#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,d;
vector<ll> x,dlt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c=0,t=0;
	cin>>c>>t;
	for(int ti=0;ti<t;ti++){
		//cout<<'\n';
		cin>>n>>d;
		//cout<<n<<" "<<d<<'\n';
		x.resize(n+1,0);
		dlt.resize(n+1,0);
		cin>>x[0];
		bool dengcha=true;
		for(int i=1;i<n;i++){
			cin>>x[i];
			dlt[i-1]=x[i]-x[i-1];
		}
		for(int i=0;i<n-2;i++){
			if(dlt[i]!=dlt[i+1]){
				dengcha=false;
			}
		}
		if(dengcha){
			if(dlt[0]>=d){
				cout<<0<<'\n';
				continue;
			}
			ll ansp=d*2/dlt[0]-1;
			if(n-ansp>=0)cout<<n-ansp<<'\n';
			else cout<<0<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
} 
