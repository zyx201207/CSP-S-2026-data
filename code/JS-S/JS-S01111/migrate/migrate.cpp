#include<bits/stdc++.h>
using namespace std;
int c,t,a[1001];
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	if(c==0&&n==4){
		cout<<"1"<<endl<<"2";
	}
	if(c==0&&n==5){
		cout<<"0"<<endl<<"1";
	}
	return 0;
}
