#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x[20005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		int t=x[2]-x[1];
		int l=2*d-1;
		int sum=x[n]-x[1]-l+1;
		if(sum>=0) cout<<sum;
		else if(sum<0) cout<<0;
	}
	return 0;
}

