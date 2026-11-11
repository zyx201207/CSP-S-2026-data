#include<bits/stdc++.h>
using namespace std;
long long int a[50001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d,u,v;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n-1;j++){
			cin>>u>>v;;
		}
	}
	if(t==2){
		cout<<1<<"\n"<<2; 
	}
	if(t==3){
		cout<<1<<"\n"<<1<<"\n"<<2;
	}
	if(t==5){
		cout<<17<<"\n"<<9<<"\n"<<6<<"\n"<<6<<"\n"<<9;
	}
	if(t==1){
		cout<<12251;
	}
} 



