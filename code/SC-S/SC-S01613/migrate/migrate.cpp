#include<bits/stdc++.h>
using namespace std;
long long a[4000000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1||d>=n){
			cout<<0<<"\n";
			break;
		}
		int v=0;
		long long t=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=t)v=1;
		}
		if(v==0){
			long long s=d+d-1;
			cout<<a[n]-a[1]-s+1<<"\n";
		} 
		
	}
	return 0;
} 