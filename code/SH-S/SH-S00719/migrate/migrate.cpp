#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3 && x[i]-x[i-1]!=x[i-1]-x[i-2]){
				f=0;
			}
		}
		if(f){
			ll sub=x[2]-x[1];
			if(d<sub){
				cout<<"0\n";
				continue;
			}
			if(d%sub!=0){
				ll s=n-d-1;
				for(int i=4;i<=n;i+=2){
					
				}
				cout<<s<<"\n";
			}
			else{
				cout<<"0\n";
			}
			continue;
		}
		cout<<"0\n";
	}
	return 0;
}
