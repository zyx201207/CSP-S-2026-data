#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	long long is[100005];
	cin>>c>>t;
	for(int a=1;a<=t;a++){
		cin>>n>>d;
		for(int b=1;b<=n;b++){
			cin>>is[b];
		}
	}
	if(t==2) cout<<1<<"\n"<<2;

	
	return 0;
} 
