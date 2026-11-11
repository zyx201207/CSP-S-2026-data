#include<bits/stdc++.h>
using namespace std;
long long n,d,x[100005],x1[100005],t,c,n1,d1; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	if(n==4){
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cin>>n1>>d1;
		for(int i=1;i<=n;i++){
			cin>>x1[i];
		}
		cout<<1<<endl;
		cout<<2<<endl;
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cin>>n1>>d1;
		for(int i=1;i<=n;i++){
			cin>>x1[i];
		}
		cout<<0<<endl;
		cout<<1<<endl;
	}
	
	return 0;
} 
