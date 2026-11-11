#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int c,t,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool ok=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				ok=1;
				break;
			}
		}
		if(!ok){
			int k=d/abs(a[2]-a[1]);
			if(k==0||k==1||k==n)cout<<0<<endl;
			else{
				cout<<n-2*k+1<<endl;	
			}
		}
	}
	return 0;
} 
