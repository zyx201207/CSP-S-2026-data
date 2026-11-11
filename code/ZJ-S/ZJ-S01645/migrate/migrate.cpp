#include<iostream>
using namespace std;
long long c,t,x[1000009],n,d,r=1,r1=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		r=1,r1=1;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int i=2;i<=n-1;i++){
			if(x[i+1]-x[i]!=x[i]-x[i-1]){
				r=0;
				break;
			} 
		}
		if(r){
			cout<<0<<endl;
			continue;
		}
		if(x[n]-x[1]>d){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if(x[j]-x[1]<=d&&x[1]-x[j]<=d)r1++;
		}
		if(r==2){
			cout<<1<<endl;
			continue;
		}
		cout<<n/3<<endl;
	}
	return 0;
} 
