#include<bits/stdc++.h>
#define int long long
#define pii pair<long,long>
using namespace std;
const int N=2e6+9;
int x[N];
int n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<endl;
		}
		else{
			int k=d/(x[2]-x[1]);
			if(k<=1){
				cout<<0<<"\n";
				continue;
			}
			if(n<k*2-1){
				cout<<0<<"\n";
			}
			else cout<<n-k*2+1<<"\n";
		}
	}
	return 0;
}
