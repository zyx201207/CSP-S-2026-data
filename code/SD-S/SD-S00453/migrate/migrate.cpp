#include<bits/stdc++.h>
using namespace std;   

#define ll long long
const int N=2e6+5;
int c,t;
int n;
ll d,x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ll h=x[2]-x[1];
		ll s=d/h;
		if(s==0){
			cout<<"0\n";
			continue;
		}
		ll ans=0;
		for(int i=s;i<n;i++){
			if(i%s!=0){
				ans+=(n-i)*(i+s-1)/s;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
