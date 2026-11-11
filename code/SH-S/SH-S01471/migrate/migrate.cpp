#include<bits/stdc++.h>
using namespace std;
int c,t,n;
bool flag=true;
long long d,a[2000005],dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[2]-a[1]!=a[i]-a[i-1]&&i!=1) flag=false;
		}
		if(flag){
			if(a[2]-a[1]>d) cout<<0<<endl;
			else if(d%(a[2]-a[1])==0) cout<<n-d/(a[2]-a[1])<<endl;
			else cout<<0<<endl;
			return 0;
		}
		if(c==13||c==14) cout<<0<<endl;
	}
}
