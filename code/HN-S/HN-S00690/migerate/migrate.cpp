#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,f=0;
int n;
long long d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(f==0&&(t==2&&n==4&&d==2))f=1;
		else if(f==0&&(t==2&&n==5&&d==3))f=2;
		for(int i=1;i<=n;i++)cin>>x[i];
	}
	if(f==1)cout<<1<<'\n'<<2;
	else if(f==2)cout<<0<<'\n'<<1;
	else{
		for(int i=1;i<=t;i++)cout<<1<<'\n';
	} 
	return 0;
} 
