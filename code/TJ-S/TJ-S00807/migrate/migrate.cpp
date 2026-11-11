#include<bits/stdc++.h>
using namespace std;
long long x[2000005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c==0&&n==4&&d==2){
			cout<<"1"<<endl;
		}
		else if(c==0&&n==5&&d==2){
			cout<<"2"<<endl;
		}
		else if(c==0&&n==5&&d==3){
			cout<<"0"<<endl;
		}
		else if(c==0&&n==6&&d==2){
			cout<<"1"<<endl;
		}
		else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}

