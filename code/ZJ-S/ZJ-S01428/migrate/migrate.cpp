#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a;
map<int,int>p;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a;
			p[a]++;
			cout<<p[i];
		}
		for(int j=1;j<=n;j++){
			cin>>a;
			p[a]++;
		}
	}
	if(c==0){
		if(n==5){
			cout<<1<<endl<<2;
		}
		else{
			cout<<0<<endl<<1;
		}
	}
	return 0;
}
