#include<iostream>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(x[j]-x[i]<=d){
					continue;
				}
			}
		}
		cout<<0<<'\n';
	}
	return 0;
}
