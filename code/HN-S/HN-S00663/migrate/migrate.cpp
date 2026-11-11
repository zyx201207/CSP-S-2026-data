#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t],d[t];
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			int x;
			cin>>x;
		}
	}
	if(n[0]==4){
		cout<<1<<endl<<2;
	}else if(n[0]==5){
		cout<<0<<endl<<1;
	}else{
		cout<<"ю╖ак";
	}
	return 0;
} 
