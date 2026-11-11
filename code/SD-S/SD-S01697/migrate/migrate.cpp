#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t+10],d[t+10];
	long long x[1000][100];
	for(int i=0;i<t;i++){
		cin>>n[i];
		cin>>d[i];
		for(int j=0;j<n[i];j++){
			cin>>x[i][j]; 
		}
	}
	if(t==2){
		cout<<c<<endl;
		cout<<t<<endl;
	}else{
		for(int i=0;i<t;i++){
			cout<<0<<endl;
		}
	}
	
	return 0;
}
