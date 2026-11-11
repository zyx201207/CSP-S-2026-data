#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],a[2000005]={};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	a[0]=1;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[2]-x[1]>d) cout<<0<<endl;
		else{
			for(int i=1;i<=n;i++){
				a[i]=a[i-1]+i-1;
			}
			cout<<a[n-3]<<endl;
		}
	}
		return 0;
} 
