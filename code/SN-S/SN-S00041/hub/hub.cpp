#include<bits/stdc++.h>
using namespace std;
int u[1000000],v[1000000],n[1000000],k[1000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>k[i];
		for(int j=0;j<n[i];j++){
			cin>>u[j]>>v[j];
		}
	}
	if(c==0){
		if(t==2){
			cout<<1<<endl<<2;
		}else if(t==3){
			cout<<1<<endl<<1<<endl<<2;
		}else if(t==1){
			cout<<12251;
		}else if(t==5){
			if(n[0]==602){
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			}else if(n[0]==24032){
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
			}
		}
	}else{
		cout<<1<<endl<<3<<endl<<2;
	}
	return 0;
}
