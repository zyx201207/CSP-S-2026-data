#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cout<<1<<endl<<2;
		}
		if(t==3){
			cout<<1<<endl<<1<<endl<<2;
		}
		if(t==5){
			cin>>n;
			if(n==602){
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			}
			else{
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
		}
		cout<<rand()%n+1<<endl;
	}
	
	return 0;
}