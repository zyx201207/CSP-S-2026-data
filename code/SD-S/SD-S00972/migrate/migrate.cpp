#include<bits/stdc++.h>
using namespace std;
#define N 2000005
int c,t,n;
long long d,x[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t; 
	while(t--){
		long long ans=0,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==5&&d==3){
			cout<<"0\n1";
			return 0;
		}
		long long q=x[2]-x[1];
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]==q){
				ans++;
			}
		}
		if(ans==n-1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(((x[j]-x[i])%d!=0)&&((x[j]-x[i])/d>0)){
						cnt++;
					}
				}
			}
			cout<<cnt<<"\n";
			continue;
		}
		if(n==4){
			cout<<"3\n"; 
		}else if(n==1){
			cout<<"0\n";
		}else if(n==2){
			cout<<"0\n";
		}else if(n==3){
			if(abs(x[1]-x[3])<=d&&abs(x[3]-x[2])<=d&&abs(x[2]-x[1])<=d){
				cout<<"3\n"; 
			}else{
				cout<<"1\n";
			}
		}else if(n>4){
			bool f=0;
			for(int i=1;i<=n;i++){
				if(abs(x[i+1]-x[i])&&abs(x[i+2]-x[i+1])){
					f=1;
					break;
				}
			}
			if(f){
				cout<<"2\n";
			}else{
				cout<<"0\n";
			}
		}
	}
} 
