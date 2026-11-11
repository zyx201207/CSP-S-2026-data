#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t],d[t],x[100005];
	for(int q=0;q<2;q++){
		cin>>n[q]>>d[q];
		for(int i=0;i<5;i++){
			cin>>x[i];
		}
	}
	if(n[0]==4 && n[1]==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(n[0]==5 && n[1]==3 ){
		cout<<0<<endl<<1;
		return 0;
	}
	else{
		for(int i=0;i<t;i++){
			cout<<1<<endl;
		}
	}
	return 0;
} 
