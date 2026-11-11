#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long a[100005]={0};
		long long d[100005]={0};
		int n,d;
		cin>>n>>d;
		int d[0]=0;
		for(int j=1;i<=n;i++){
			cin>>a[i];
			d[i]=a[i]-a[i-1];
		}
		if(d[i]==d[i+1]){
			cout<<0;
		}
	}
	
	cout<<1<<endl;
	cout<<2;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

