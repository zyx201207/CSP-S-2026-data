#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool A=1;
		int k=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=k) A=0;
		}
		if(A){
			if(d<k*2) cout<<"0\n";
			else{
				int t=d/k;
				cout<<(n-t*2+1)<<"\n";
			}
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}