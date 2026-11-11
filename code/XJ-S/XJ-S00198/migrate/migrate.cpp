#include<bits/stdc++.h>
using namespace std;
int n[100086],d[1000086],a[100086];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; 
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++){
			cin>>a[i];
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(n%2==1){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	if(sum==0){
		cout<<0<<endl;
	}
	
	return 0;
} 
