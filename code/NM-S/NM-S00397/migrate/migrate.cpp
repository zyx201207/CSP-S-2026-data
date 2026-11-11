#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long  c,t;
	cin>>c>>t;
	long long n,d,q,e;
	cin>>n>>d;
	long long x[10000];
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
		if(fabs(x[j]-x[j-1])<=d){
		
		min(x[j],x[j+1]);
		q=q+1;
		if(q==2)e=e+1;
		}
		
	
	}
	cout<<e;}
	return 0;
}
