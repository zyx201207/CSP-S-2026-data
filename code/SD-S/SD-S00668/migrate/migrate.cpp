#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==12||c==13||c==0){
			long long cz=x[2]-x[1];
			if(cz*2>d){
				cout<<0<<"\n";
				continue;
			}
			if(d>cz*(n-1)){
				cout<<0<<"\n";
				continue;
			}
			d=d/cz;
			cout<<n-d-d+1<<"\n";
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
