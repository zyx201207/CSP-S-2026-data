#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int ss(int b){
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d; 
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		ss(n);
		if(n<4){
			cout<<0<<endl;
		}else{
			int m1=0,m2=m1+3;
			int f=a[m1],l=a[m2];
			
		}
	}
	 
	return 0;
}
