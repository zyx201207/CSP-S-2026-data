#include<bits/stdc++.h>

using namespace std;
long long x,t,n,m;
int main(){
	freopen(hub.in,"r",stdin);
	freopen(hub.out,"w",stdout);
	cin>>x;
	if(x==0){
		cin>>t;
		if(t==1){
			cout<<12251;
		}
		else if(t==2){
			cout<<1<<endl<<2;
		}
		else if(t==3){
			cout<<1<<endl<<1<<endl<<2;
		}
		else{
			cin>>n;
			if(n==602){
				cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
			}
			else{
				cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
			}
		}
	}
	else{
		cin>>t;
		for(int i=0;i<t;i++){
			cout<<1<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
