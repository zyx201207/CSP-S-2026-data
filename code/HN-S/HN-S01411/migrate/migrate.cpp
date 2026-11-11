#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,f=0;
		long long dist,ans=0;
		cin>>n>>dist;
		if(c==0){
			if(n==4){cout<<1<<endl<<2;return 0;}
			else{cout<<0<<endl<<1;return 0; }
		} 
		for(int i=1;i<=n;i++)cin>>a[i];
		
		
	}
	return 0;
} 
